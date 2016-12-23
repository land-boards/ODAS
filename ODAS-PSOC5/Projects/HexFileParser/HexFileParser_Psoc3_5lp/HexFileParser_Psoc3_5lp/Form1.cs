using System;
using System.IO;
using System.ComponentModel;
using System.Windows.Forms;

namespace HexFileParser_Psoc3_5lp
{
    /// <summary>
    /// Class containing the hex file parsing logic
    /// </summary>
    public partial class FormHexFileParser_Psoc3_5lp : Form
    {
        /* Constant Defintions */

        /* Parsing state machine - state definitions */
        internal const int SEEK_PARSE_STATE = 0;
        internal const int FLASH_PARSE_STATE = 1;
        internal const int SILICON_ID_PARSE_STATE = 2;
        internal const int DEVICE_CFG_NVL_PARSE_STATE = 3;
        internal const int WO_NVL_PARSE_STATE = 4;
        internal const int CHECKSUM_PARSE_STATE = 5;
        internal const int FLASH_PROTECTION_PARSE_STATE = 6;
        internal const int EEPROM_PARSE_STATE = 7;
        internal const int EXIT_STATE = 8;

        /* Memory size, hex file record definitions */

        internal const int MAX_DATA_BYTES_PER_HEX_ROW = 64;
        internal const int MAX_DATA_CHARACTERS_PER_HEX_ROW = 128;

        internal const int CODE_BYTES_PER_FLASH_ROW = 256;
        internal const int FLASH_ROWS_PER_ARRAY = 256;
        internal const int FLASH_DATA_HEADER_LENGTH = 9;

        internal const int END_OF_LINE_CHECKSUM_CHAR_COUNT = 2;

        internal const int HEX_FILE_LINES_PER_FLASH_ROW = 4;

        internal const int FLASH_ROWS_PER_PROTECTION_BYTE = 4;

        internal const int MAX_FLASH_PROTECTION_BYTES_PER_ARRAY = 64;

        internal const int HEX_FILE_COLON_CHAR_INDEX = 0;
        internal const int HEX_FILE_BYTE_COUNT_CHAR_0_INDEX = 1;
        internal const int HEX_FILE_BYTE_COUNT_CHAR_1_INDEX = 2;
        internal const int HEX_FILE_ADDR_CHAR_0_INDEX = 3;
        internal const int HEX_FILE_ADDR_CHAR_1_INDEX = 4;
        internal const int HEX_FILE_ADDR_CHAR_2_INDEX = 5;
        internal const int HEX_FILE_ADDR_CHAR_3_INDEX = 6;
        internal const int HEX_FILE_RECORD_TYPE_CHAR_0_INDEX = 7;
        internal const int HEX_FILE_RECORD_TYPE_CHAR_1_INDEX = 8;
        internal const int HEX_FILE_DATA_CHAR_0_INDEX = 9;
        internal const char HEX_FILE_DATA_RECORD_CHAR_0 = '0';
        internal const char HEX_FILE_DATA_RECORD_CHAR_1 = '0';
        internal const char HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_0 = '0';
        internal const char HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_1 = '4';
        internal const char HEX_FILE_EXTENDED_ADDR_NON_FLASH_REGION = '8';

        internal const int CFG_BYTES_PER_FLASH_ROW = 32;
        internal const int FLASH_CFG_HEADER_LENGTH = 9;
        internal const string FLASH_CFG_REGION_START = ":0200000480007A";

        internal const int DEVICE_CFG_NVL_BYTE_LENGTH = 4;
        internal const int DEVICE_CFG_NVL_HEADER_LENGTH = 9;
        internal const string DEVICE_CFG_NVL_REGION_START = ":0200000490006A";

        internal const int WO_NVL_BYTE_LENGTH = 4;
        internal const int WO_NVL_HEADER_LENGTH = 9;
        internal const string WO_NVL_REGION_START = ":0200000490105A";

        internal const int BYTES_PER_EEPROM_ROW = 16;
        internal const int MAX_ROWS_PER_EEPROM_SECTOR = 64;
        internal const int EEPROM_ROWS_PER_HEX_LINE = 4;
        internal const int EEPROM_HEADER_LENGTH = 9;
        internal const string EEPROM_REGION_START = ":0200000490204A";

        internal const int CHECKSUM_HEADER_LENGTH = 9;
        internal const int CHECKSUM_BYTE_LENGTH = 2;
        internal const string CHECKSUM_REGION_START = ":0200000490303A";

        internal const int FLASH_PROTECTION_HEADER_LENGTH = 9;
        internal const string FLASH_PROTECTION_REGION_START = ":0200000490402A";

        internal const int SILICON_ID_HEADER_LENGTH = 13;
        internal const int SILICON_ID_BYTE_LENGTH = 4;
        internal const string SILICON_ID_REGION_START = ":0200000490501A";

        internal const int HEX_FILE_UNDEFINED_DEVICE_FAMILY = 0;
        internal const int HEX_FILE_PSOC3_DEVICE_FAMILY = 1;
        internal const int HEX_FILE_PSOC5LP_DEVICE_FAMILY = 2;

        internal const string PSOC3_FAMILY_ID = "E0";
        internal const string PSOC5LP_FAMILY_ID = "E1";

        internal const int FAMILY_ID_CHAR_0_INDEX = 1;
        internal const int FAMILY_ID_CHAR_1_INDEX = 2;
        
        /* Global variables */

        string m_pathHexFile, m_pathCfile, m_pathHfile; /* Path variables for Source Hex File, Target .c, .h file locations */
        string m_seekStateString; /* String storing the last read line from hex file stream reader for processing in seek state */
        StreamWriter m_swCfile; /* Stream Writer object to .c file */
        StreamWriter m_swHfile; /* Stream Writer object to .h file */
        StreamReader m_srHexData;  /* Hex File Stream Reader object to get main Flash data and other non-flash data in hex file */
        StreamReader m_srHexFlashCfgData;  /* Hex File Stream Reader object to get Cfg Flash data */
        bool m_eccEnabledFlag;  /* Indicates if Flash ECC feature is enabled or not */
        int m_numberOfFlashRows; /* Total number of Flash rows in hex file */
        int m_numberOfFlashArrays; /* Total number of Flash arrays in hex file */
        int m_bytesPerFlashRow;      /* Bytes per row of flash */
        int m_numberOfEepromRows; /* Total number of Eeprom rows in hex file */
        int m_numberOfEepromSectors; /* Total number of Eeprom sectors in hex file */

        int m_parseState; /* Parsing state machine variable */

        int m_deviceFamily;

        /* Code generated automatically by Visual Studio */
        public FormHexFileParser_Psoc3_5lp()
        {
            InitializeComponent();

            openFileDialogSourceHex.InitialDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "\\PSoC Creator\\");
        }


        private void buttonSourceHexFile_Click(object sender, EventArgs e)
        {
            /* Show files with extension *.hex */
            openFileDialogSourceHex.Title = "Open Hex File";
            openFileDialogSourceHex.Filter = "Hex files (*.hex)|*.hex";
            openFileDialogSourceHex.FilterIndex = 1;
            openFileDialogSourceHex.RestoreDirectory = true;

            /* If hex file exists, get the hex file name and display in text box */
            if (openFileDialogSourceHex.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if (openFileDialogSourceHex.OpenFile() != null)
                    {
                        textBoxHexFile.Text = openFileDialogSourceHex.FileName;
                    }
                }
                /* File does not exist exception */
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not open the file from the disk. Original error: " + ex.Message);
                }
            }
        }

        private void buttonTargetLocation_Click(object sender, EventArgs e)
        {
            /* If folder exists, display folder location in text box */
            if (folderBrowserDialogTargetFile.ShowDialog() == DialogResult.OK)
            {
                if (folderBrowserDialogTargetFile.SelectedPath != null)
                {
                    textBoxTargetLocation.Text = folderBrowserDialogTargetFile.SelectedPath;
                }
            }
        }

        private void textBoxHexFile_MouseHover(object sender, EventArgs e)
        {
            toolTipMessage.SetToolTip(textBoxHexFile, textBoxHexFile.Text);
        }

        private void textBoxTargetLocation_MouseHover(object sender, EventArgs e)
        {
            toolTipMessage.SetToolTip(textBoxTargetLocation, textBoxTargetLocation.Text);
        }

        private void buttonParser_Click(object sender, EventArgs e)
        {
            DialogResult result = DialogResult.Yes;
            String messageText = null;

            /* Get the path locations for source, target files */
            m_pathHexFile = textBoxHexFile.Text;
            m_pathCfile = Path.Combine(textBoxTargetLocation.Text, "HexImage.c");
            m_pathHfile = Path.Combine(textBoxTargetLocation.Text, "HexImage.h");

            /* Abort if source hex file does not exist at the specified location */
            if (!File.Exists(m_pathHexFile))
            {
                MessageBox.Show("Hex file does not exist at the specified location");
                return;
            }

            /* If files exist at the target folder location, get user permission before overwriting those files */
            if (File.Exists(m_pathCfile) || File.Exists(m_pathHfile))
            {
                result = MessageBox.Show("Warning: File(s) with the name HexImage.h (.c) already exist in the Target folder location. Do you want to replace those files with the new ones?", "Message", MessageBoxButtons.YesNo);
            }

            if (result == DialogResult.No)
            {
                return;
            }

            /* Delete files which already exist */
            try
            {
                if (File.Exists(m_pathCfile))
                {
                    File.Delete(m_pathCfile);
                }

                if (File.Exists(m_pathHfile))
                {
                    File.Delete(m_pathHfile);
                }
            }
            catch (Exception ex)
            {
                messageText = String.Concat("The file(s) could not be deleted. Exception: ", ex.Message);
                MessageBox.Show(messageText, "Message", MessageBoxButtons.OK);

                return;
            }

            /* Create a new HexImage.c, HexImage.h files at specified location */

            /* Create a .c file to write the data. */
            using (m_swCfile = File.CreateText(m_pathCfile))
            {
                WriteSourceFile();              /* Create the .c file */
                m_swCfile.Close();                /* Close .c file */
            }

            /* Create a file to write the data */
            using (m_swHfile = File.CreateText(m_pathHfile))
            {
                WriteHeaderFile();              /* Create the .h file */
                m_swHfile.Close();                /* Close .h file */
            }

            MessageBox.Show("Hex File Parsing Completed", "Message", MessageBoxButtons.OK);
        }

        /* Generate the source file */
        private void WriteSourceFile()
        {
            AppendSourceFileHeader();       /* Add top level comments to generated .c file */
            ParseHexFile();                 /* Parse Hex file and add to .c file */
            AppendSourceFileTrailer();      /* Add closing comments to generated .c file */
        }

        /* Add top level comments to generated .c file */
        private void AppendSourceFileHeader()
        {
            String SourceHeader = "/*****************************************************************************\n" +
                                  "* File Name: HexImage.c\n" +
                                  "**\n" +
                                  "Version: 3.0\n" +
                                  "**\n" +
                                  "Description:\n" +
                                  "* 1.) This source file defines the Hex file data as an Array of constants.\n" +                                  
                                  "* 2.) This source file is generated by C# application \"HexFileParser_Psoc3_5lp\"\n" +
                                  "      with the actual hex file to be programmed as input to the C# application.\n" +
                                  "*\n" +
                                  "**\n" +
                                  "Note:\n" +
                                  "*\n" +
                                  "**\n" +
                                  "Owner:\n" +
                                  "* VVSK\n" +
                                  "**\n" +
                                  "Related Document:\n" +
                                  "* Refer to the application note document for details on the application\n" +
                                  "**\n" +
                                  "IDE Info:\n" +
                                  "* 1. Microsoft Visual C# 2010 Express used to develop C# application\n" +
                                  "*****************************************************************************/ \n\n" +
                                  "#include \"HexImage.h\" \n";

            m_swCfile.Write(SourceHeader);
            m_swCfile.WriteLine();
        }


        private void ParseHexFile()
        {
            /* Initialize variables */
            m_eccEnabledFlag = false;
            m_numberOfFlashRows = 0;
            m_numberOfFlashArrays = 0;
            m_bytesPerFlashRow = 0;
            m_numberOfEepromRows = 0;
            m_numberOfEepromSectors = 0;
            m_deviceFamily = HEX_FILE_UNDEFINED_DEVICE_FAMILY;
            m_parseState = FLASH_PARSE_STATE; 
            
            /* Initialize file reader pointer */
            m_srHexData = File.OpenText(m_pathHexFile);

            /* Parsing State machine logic */
            while(m_parseState != EXIT_STATE)
            {
                switch (m_parseState)
                {
                    case FLASH_PARSE_STATE:
                        ParseFlash(); /* Flash, Flash configuration data */
                        m_parseState = SEEK_PARSE_STATE;

                        break;

                    case SEEK_PARSE_STATE:
                        ProcessSeekState(); 
                        break;

                    case DEVICE_CFG_NVL_PARSE_STATE:
                        ParseDeviceConfigNvl();
                        m_parseState = SEEK_PARSE_STATE;
                        
                        break;

                    case WO_NVL_PARSE_STATE:
                        ParseWriteOnceNvl();
                        m_parseState = SEEK_PARSE_STATE;

                        break;

                    case EEPROM_PARSE_STATE:
                        ParseEeprom();
                        m_parseState = SEEK_PARSE_STATE;

                        break;

                    case CHECKSUM_PARSE_STATE:
                        ParseChecksum();
                        m_parseState = SEEK_PARSE_STATE;

                        break;

                    case FLASH_PROTECTION_PARSE_STATE:
                        ParseFlashProtectionData();
                        m_parseState = SEEK_PARSE_STATE;

                        break;

                    case SILICON_ID_PARSE_STATE:
                        ParseSiliconId();
                        m_parseState = SEEK_PARSE_STATE;
                        break;

                    case EXIT_STATE:
                        break;

                    default:
                        m_parseState = EXIT_STATE;
                        break;
                }
            }
        }

        /* Search for the next memory region to parse or exit if none exists */
        private void ProcessSeekState()
        {
            switch (m_seekStateString)
            {
                case DEVICE_CFG_NVL_REGION_START:
                    m_parseState = DEVICE_CFG_NVL_PARSE_STATE;
                    break;

                case WO_NVL_REGION_START:
                    m_parseState = WO_NVL_PARSE_STATE;
                    break;

                case EEPROM_REGION_START:
                    m_parseState = EEPROM_PARSE_STATE;
                    break;

                case CHECKSUM_REGION_START:
                    m_parseState = CHECKSUM_PARSE_STATE;
                    break;

                case FLASH_PROTECTION_REGION_START:
                    m_parseState = FLASH_PROTECTION_PARSE_STATE;
                    break;

                case SILICON_ID_REGION_START:
                    m_parseState = SILICON_ID_PARSE_STATE;
                    break;

                default:
                    m_parseState = EXIT_STATE;
                    break;                       
            }
        }


        /* Add EEPROM data from hex file to generated .c file */
        private void ParseEeprom()
        {
            String readData;
            bool oneTimePassDone = false;
            int charOffset = 0;

            String eepromHeaderString = "unsigned char const eepromData_hexFile[NUMBER_OF_EEPROM_ROWS_HEX_FILE][EEPROM_ROW_BYTE_SIZE_HEX_FILE]  = { ";
            String dummyHeaderString = "";
            for (int i = 0; i < eepromHeaderString.Length; i++)
            {
                dummyHeaderString += " ";
            }

            m_swCfile.WriteLine(eepromHeaderString);

            while ((readData = m_srHexData.ReadLine()) != null)
            {
                /* EEPROM ends on the next extended linear record occurrence */
                if ((readData[HEX_FILE_RECORD_TYPE_CHAR_0_INDEX] == HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_0) & (readData[HEX_FILE_RECORD_TYPE_CHAR_1_INDEX] == HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_1))
                {
                    m_swCfile.WriteLine("}");
                    dummyHeaderString = dummyHeaderString.Remove(0, 2);
                    m_swCfile.WriteLine(dummyHeaderString + "};");
                    m_swCfile.WriteLine();

                    break;
                }
                /* Braces at the end of each EEPROM row */
                else if (oneTimePassDone == true)
                {
                    m_swCfile.WriteLine("},");
                }

                readData = readData.Remove(0, EEPROM_HEADER_LENGTH);

                charOffset = 0;

                /* Each hex file line has data for 4 EEPROM rows */
                for(int i = 0; i < EEPROM_ROWS_PER_HEX_LINE; i++)
                {
                    m_swCfile.Write(dummyHeaderString + "{");

                    charOffset = (i * BYTES_PER_EEPROM_ROW * 2); /* Starting location of row data in hex file data */

                    /* Write row data to c file */
                    for (int j = 0; j < BYTES_PER_EEPROM_ROW; j++)
                    {
                        m_swCfile.Write("0x" + readData[charOffset + (2 * j)] + readData[charOffset + ((2 * j) + 1)]);
                        if (j != (BYTES_PER_EEPROM_ROW - 1))
                        {
                            m_swCfile.Write(", "); /* Not last byte in eeprom row */
                        }
                    }
                    if (i != (EEPROM_ROWS_PER_HEX_LINE - 1))
                    {
                        m_swCfile.WriteLine("},"); /* last byte in eeprom row */
                    }
                }

                m_numberOfEepromRows += EEPROM_ROWS_PER_HEX_LINE;

                oneTimePassDone = true; /* bool flag set to add braces at the end of each EEPROM row */
            }

            /* Calculate the number of EEPROM sectors */
            if (m_numberOfEepromRows % MAX_ROWS_PER_EEPROM_SECTOR == 0)
            {
                m_numberOfEepromSectors = m_numberOfEepromRows / MAX_ROWS_PER_EEPROM_SECTOR;
            }
            else
            {
                m_numberOfEepromSectors = (m_numberOfEepromRows / MAX_ROWS_PER_EEPROM_SECTOR) + 1;
            }            

            m_seekStateString = readData; /* Next record that will be processed in the seek state */
        }


        /* Add Flash data from hex file to generated .c file */
        private void ParseFlash()
        {
            String readData;
            String hexRowData;
            String cfgData = null;
            bool oneTimePassDone = false;
            bool secondTimeCfgRead = false;

            /* Start -  ECC enabled checking logic */
            m_eccEnabledFlag = true; /* Assume ECC is  enabled by default */
            m_bytesPerFlashRow = CODE_BYTES_PER_FLASH_ROW; /* Flash row size for ECC enabled state */
            m_srHexFlashCfgData = File.OpenText(m_pathHexFile);
            while((readData = m_srHexFlashCfgData.ReadLine()) != null)
            {
                if (readData == FLASH_CFG_REGION_START)
                {
                    m_eccEnabledFlag = false;
                    m_bytesPerFlashRow = CODE_BYTES_PER_FLASH_ROW + CFG_BYTES_PER_FLASH_ROW; /* Flash row size for ECC disabled state */
                    break;
                }
            }
            /* Stop -  ECC enabled checking logic */

            String flashHeaderString = "unsigned char const flashData_hexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE][FLASH_ROW_BYTE_SIZE_HEX_FILE]  = { ";
            String dummyHeaderString = "";
            for (int i = 0; i < flashHeaderString.Length; i++)
            {
                dummyHeaderString += " ";
            }

            m_swCfile.WriteLine(flashHeaderString);

            while ((readData = m_srHexData.ReadLine()) != null)
            {
                /* Data type record */
                if ((readData[HEX_FILE_RECORD_TYPE_CHAR_0_INDEX] == HEX_FILE_DATA_RECORD_CHAR_0) & (readData[HEX_FILE_RECORD_TYPE_CHAR_1_INDEX] == HEX_FILE_DATA_RECORD_CHAR_1))
                {
                    m_numberOfFlashRows++;

                    if (oneTimePassDone == true)
                    {
                        m_swCfile.WriteLine("},");  /* Append braces to end of each flash row from previous loop */
                    }

                    m_swCfile.Write(dummyHeaderString + "{"); /* Append braces to start of each flash row for this loop */
                }
                /* Extended linear address record */
                else if ((readData[HEX_FILE_RECORD_TYPE_CHAR_0_INDEX] == HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_0) & (readData[HEX_FILE_RECORD_TYPE_CHAR_1_INDEX] == HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_1))
                {
                    /* Stop parsing when flash address region has crossed the address boundary limit */
                    if (readData[HEX_FILE_DATA_CHAR_0_INDEX] >= HEX_FILE_EXTENDED_ADDR_NON_FLASH_REGION)
                    {
                        m_swCfile.WriteLine("}");
                        dummyHeaderString = dummyHeaderString.Remove(0, 2);
                        m_swCfile.WriteLine(dummyHeaderString + "};");
                        m_swCfile.WriteLine();

                        /* If ECC is disabled, advanced main pointer to end of ECC region and reduce seek time */
                        if (m_eccEnabledFlag == false)
                        {
                            m_srHexData = m_srHexFlashCfgData;
                            readData = m_srHexData.ReadLine(); /* String to process in seek state */
                        }

                        m_seekStateString = readData; /* String to process in seek state */

                        return;
                    }
                    /* If the extended region is within flash memory boundary, move to the next record */
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    /* Invalid Condition */
                    m_numberOfFlashRows = 0;
                    m_seekStateString = null;
                    return;
                }

                readData = readData.Remove(0, FLASH_DATA_HEADER_LENGTH); /* Remove the meta data at the beginning of the line in the hex file */
                readData = readData.Remove(MAX_DATA_CHARACTERS_PER_HEX_ROW, END_OF_LINE_CHECKSUM_CHAR_COUNT); /* Remove the meta data at the end of the line in the hex file */

                /* Write data for one flash row */
                for (int i = 0; i < (HEX_FILE_LINES_PER_FLASH_ROW - 1); i++)
                {
                    hexRowData = m_srHexData.ReadLine();
                    hexRowData = hexRowData.Remove(0, FLASH_DATA_HEADER_LENGTH); /* Remove the meta data at the beginning of the line in the hex file */
                    hexRowData = hexRowData.Remove(MAX_DATA_CHARACTERS_PER_HEX_ROW, END_OF_LINE_CHECKSUM_CHAR_COUNT); /* Remove the meta data at the end of the line in the hex file */
                    readData = readData + hexRowData; /* Append the data to form a flash row */
                }

                /* Write the 256 bytes flash row data to the .c file */
                for (int i = 0; i < CODE_BYTES_PER_FLASH_ROW; i++)
                {
                    m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);
                    if (i != (CODE_BYTES_PER_FLASH_ROW - 1))
                    {
                        m_swCfile.Write(", "); /* Except for last byte, append comma to other bytes */
                    }
                }

                /* Add flash config data if applicable */
                if (m_eccEnabledFlag == false)
                {
                    m_swCfile.Write(", "); /* append comma for last code byte */

                    /* Each line in Flash Cfg region of hex file has Cfg data for two Flash rows. This is for first flash row Cfg data */
                    if (secondTimeCfgRead == false) 
                    {
                        secondTimeCfgRead = true;
                        cfgData = m_srHexFlashCfgData.ReadLine();
                        cfgData = cfgData.Remove(0, FLASH_CFG_HEADER_LENGTH); /* Strip the meta data information from the beginning of the hex file line */
                    }
                    else 
                    {
                        secondTimeCfgRead = false;
                        cfgData = cfgData.Remove(0, (CFG_BYTES_PER_FLASH_ROW * 2)); /* Remove the first 64 bytes which are for previous flash row ECC data */
                    }
                    /* Append the cfg data for the flash row */
                    for (int i = 0; i < CFG_BYTES_PER_FLASH_ROW; i++)
                    {
                        m_swCfile.Write("0x" + cfgData[2 * i] + cfgData[(2 * i) + 1]);
                        if (i != (CFG_BYTES_PER_FLASH_ROW - 1))
                        {
                            m_swCfile.Write(", "); /* Except for last byte, append comma to other bytes */
                        }
                    }
                }

                oneTimePassDone = true;
            }

        }

        /* Add Device Configuration NVL data from hex file to generated .c file */
        private void ParseDeviceConfigNvl()
        {            
            String readData;             

            readData = m_srHexData.ReadLine();

            readData = readData.Remove(0, DEVICE_CFG_NVL_HEADER_LENGTH); /* Remove header information from hex row */

            m_swCfile.Write("unsigned char const deviceConfigNvl_hexFile[DEVICE_CFG_NVL_BYTE_SIZE_HEX_FILE] = {");

            for (int i = 0; i < DEVICE_CFG_NVL_BYTE_LENGTH; i++)
            {
                m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);
                if (i != (DEVICE_CFG_NVL_BYTE_LENGTH - 1))
                {
                    m_swCfile.Write(", "); /* Append just comma to all but last bytes of NVL */
                }
                else
                {
                    m_swCfile.WriteLine("};");   /* Last byte of NVL */                 
                }
            }
            
            m_swCfile.WriteLine();

            /* String to process in seek state */
            m_seekStateString = m_srHexData.ReadLine();
        }

        /* Add Write Once NVL data from hex file to generated .c file */
        private void ParseWriteOnceNvl()
        {
            String readData;            

            readData = m_srHexData.ReadLine();

            readData = readData.Remove(0, WO_NVL_HEADER_LENGTH); /* Remove header information from hex row */

            m_swCfile.Write("unsigned char const writeOnceNvl_hexFile[WO_NVL_BYTE_SIZE_HEX_FILE] = {");

            for (int i = 0; i < WO_NVL_BYTE_LENGTH; i++)
            {
                m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);
                if (i != (WO_NVL_BYTE_LENGTH - 1))
                {
                    m_swCfile.Write(", "); /* Append just comma to all but last bytes of NVL */
                }
                else
                {
                    m_swCfile.WriteLine("};");  /* Last byte of NVL */
                }
            }
            
            m_swCfile.WriteLine();
            
            /* String to process in seek state */
            m_seekStateString = m_srHexData.ReadLine();
        }

        /* Add Hex File Checksum data from hex file to generated .c file */
        private void ParseChecksum()
        {

           String readData;           

           readData = m_srHexData.ReadLine();

           readData = readData.Remove(0, CHECKSUM_HEADER_LENGTH); /* Remove header information from hex row */

           m_swCfile.Write("unsigned char const checksumData_hexFile[CHECKSUM_BYTE_SIZE_HEX_FILE] = {");

           for (int i = 0; i < CHECKSUM_BYTE_LENGTH; i++)
           {
                /* Checksum data is in big-endian format. Store as bytes in little endian format */
                m_swCfile.Write("0x" + readData[2 * (1 - i)] + readData[(2 * (1 - i)) + 1]);

                if (i != (CHECKSUM_BYTE_LENGTH - 1))
                {
                    m_swCfile.Write(", "); /* Append just comma to all but last bytes of checksum */
                }
                else
                {
                    m_swCfile.WriteLine("};"); /* Last byte of checksum */                   
                }
           }

           m_swCfile.WriteLine();

           /* String to process in seek state */
           m_seekStateString = m_srHexData.ReadLine();
        }

        /* Add Device Silicon ID, revision ID data  from hex file to generated .c file */
        private void ParseSiliconId()
        {
            String readData;
            String familyID;

            readData = m_srHexData.ReadLine();

            readData = readData.Remove(0, SILICON_ID_HEADER_LENGTH); /* Remove header information from hex row */

            familyID = String.Concat(readData[FAMILY_ID_CHAR_0_INDEX], readData[FAMILY_ID_CHAR_1_INDEX]);

            /* Identify the device family which the hex file belongs to */
            if(String.Equals(familyID, PSOC3_FAMILY_ID))
            {
                m_deviceFamily = HEX_FILE_PSOC3_DEVICE_FAMILY;
            }
            else if (String.Equals(familyID, PSOC5LP_FAMILY_ID))
            {
                m_deviceFamily = HEX_FILE_PSOC5LP_DEVICE_FAMILY;
            }
            else
            {
                m_deviceFamily = HEX_FILE_UNDEFINED_DEVICE_FAMILY;
            }

            /* Write device silicon ID information */
            m_swCfile.Write("unsigned char const deviceSiliconId_hexFile[SILICON_ID_BYTE_SIZE_HEX_FILE] = {");

            for (int i = 0; i < SILICON_ID_BYTE_LENGTH; i++)
            {
                m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);
                if (i != (SILICON_ID_BYTE_LENGTH - 1))
                {
                    m_swCfile.Write(", ");  /* Append just comma to all but last bytes of silicon ID */
                }
                else
                {
                    m_swCfile.WriteLine("};");   /* Last byte of silicon ID */                    
                }
            }
            
            m_swCfile.WriteLine();

            /* Write device revision ID information */
            m_swCfile.WriteLine("unsigned char const deviceRevisionId_hexFile = 0x" + readData[2 * SILICON_ID_BYTE_LENGTH] + readData[(2 * SILICON_ID_BYTE_LENGTH) +1] + ";" );
            m_swCfile.WriteLine();

            /* String to process in seek state */
            m_seekStateString = m_srHexData.ReadLine();
        }


        /* Add Flash protection data from hex file to the generated .c file */
        private void ParseFlashProtectionData()
        {
            String readData;
            int protectionLineNumber = 0;
            int protectionBytesPerArray;

            int numberOfProtectionBytes = m_numberOfFlashRows / FLASH_ROWS_PER_PROTECTION_BYTE;

            /* Calculate number of flash arrays */
            if ((m_numberOfFlashRows % FLASH_ROWS_PER_ARRAY) == 0)
            {
                m_numberOfFlashArrays = m_numberOfFlashRows / FLASH_ROWS_PER_ARRAY;
            }
            else
            {
                m_numberOfFlashArrays = (m_numberOfFlashRows / FLASH_ROWS_PER_ARRAY) + 1;
            }

            /* Loop for the required number of flash arrays */
            for(protectionLineNumber = 0; protectionLineNumber < m_numberOfFlashArrays; protectionLineNumber++)
            {
                readData = m_srHexData.ReadLine();

                readData = readData.Remove(0, FLASH_PROTECTION_HEADER_LENGTH); /* Remove the header from the hex file line */

                /* All but the last flash array have the maximum number of protection bytes */
                if (protectionLineNumber != (m_numberOfFlashArrays - 1))
                {
                    protectionBytesPerArray = MAX_FLASH_PROTECTION_BYTES_PER_ARRAY;
                }
                else
                {
                    protectionBytesPerArray = numberOfProtectionBytes - ((MAX_FLASH_PROTECTION_BYTES_PER_ARRAY * protectionLineNumber));
                }

                if (protectionLineNumber == 0)
                {
                    m_swCfile.Write("unsigned char const flashProtectionData_hexFile[FLASH_PROTECTION_BYTE_SIZE_HEX_FILE] = {");
                }

                /* Write the protection data to the .c file */
                for (int i = 0; i < protectionBytesPerArray; i++)
                {
                    m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);

                    if (protectionLineNumber == (m_numberOfFlashArrays - 1))
                    {
                        if (i == (protectionBytesPerArray - 1))
                        {
                            m_swCfile.WriteLine("};"); /* Close braces for last protection byte */
                            m_swCfile.WriteLine();
                            break;
                        }
                    }
                    m_swCfile.Write(", "); /* Append comma to each protection byte */
                }                               
            }

            /* String to process in the seek state */
            m_seekStateString = m_srHexData.ReadLine();
        }


        /* Append Trailer data for source c file */
        private void AppendSourceFileTrailer()
        {
            String sourceTrailer = "\n/* [] END OF FILE */\n";
            m_swCfile.Write(sourceTrailer);
        }

        /* Generate the header file with declaration for array of constants */
        private void WriteHeaderFile()
        {
            String headerFileTrailer;
            String headerFileHeader = "/*****************************************************************************\n" +
                      "* File Name: HexImage.h\n" +
                      "**\n" +
                      "Version: 3.0\n" +
                      "**\n" +
                      "Description:\n" +
                      "* 1.) This is the header file of HexImage.c\n" +
                      "* 2.) It provides access to the Hex file data organized as an array of constants.\n" +
                      "* 3.) This header file is generated by the C# application \"HexFileParser_Psoc3_5lp\"\n" +
                      "      with the actual hex file to be programmed as input to C# application.\n" +
                      "**\n" +
                      "Note:\n" +
                      "**\n" +
                      "Owner:\n" +
                      "* VVSK\n" +
                      "**\n" +
                      "**\n" +
                      "Related Document:\n" +
                      "* Refer to the application note document for details on the application\n" +
                      "**\n" +
                      "IDE Info:\n" +
                      "* 1. Microsoft Visual C# 2010 Express used to develop the C# application\n" +
                      "*****************************************************************************/\n" +
                      "\n" +
                      "#ifndef __HEXIMAGE_H \n" +
                      "#define __HEXIMAGE_H \n" +
                      "\n" +
                      "/*****************************************************************************\n" +
                      "* MACRO Definitions \n" +
                      "******************************************************************************/ \n";

            m_swHfile.Write(headerFileHeader);
            m_swHfile.WriteLine();
            
            m_swHfile.WriteLine("#define HEX_FILE_UNDEFINED_DEVICE_FAMILY            0u");
            m_swHfile.WriteLine("#define HEX_FILE_PSOC3_DEVICE_FAMILY                1u");
            m_swHfile.WriteLine("#define HEX_FILE_PSOC5LP_DEVICE_FAMILY              2u");
            m_swHfile.WriteLine();

            /* Generate define for applicable device family */

            m_swHfile.Write("#define HEX_FILE_DEVICE_FAMILY      ");

            switch (m_deviceFamily)
            {
                case HEX_FILE_UNDEFINED_DEVICE_FAMILY:
                    m_swHfile.WriteLine("HEX_FILE_UNDEFINED_DEVICE_FAMILY");
                    break;

                case HEX_FILE_PSOC3_DEVICE_FAMILY:
                    m_swHfile.WriteLine("HEX_FILE_PSOC3_DEVICE_FAMILY");
                    break;

                case HEX_FILE_PSOC5LP_DEVICE_FAMILY:
                    m_swHfile.WriteLine("HEX_FILE_PSOC5LP_DEVICE_FAMILY");
                    break;

                default:
                    m_swHfile.WriteLine("HEX_FILE_UNDEFINED_DEVICE_FAMILY");
                    break;
            }

            m_swHfile.WriteLine();

            /* Generate define if flash configuration region is present in hex file */
            if (m_eccEnabledFlag == false)
            {
                m_swHfile.WriteLine("#define FLASH_CFG_DATA_PRESENT_HEX_FILE       1u");
            }
            else
            {
                m_swHfile.WriteLine("#define FLASH_CFG_DATA_PRESENT_HEX_FILE       0u");
            }

            m_swHfile.WriteLine();

            /* Generate define if EEPROM region is present in hex file */
            if (m_numberOfEepromRows != 0)
            {
                m_swHfile.WriteLine("#define EEPROM_DATA_PRESENT_HEX_FILE       1u");
            }
            else
            {
                m_swHfile.WriteLine("#define EEPROM_DATA_PRESENT_HEX_FILE       0u");
            }

            m_swHfile.WriteLine();
            m_swHfile.WriteLine("#define NUMBER_OF_EEPROM_ROWS_HEX_FILE      " + Convert.ToString(m_numberOfEepromRows) + "u");
            m_swHfile.WriteLine("#define NUMBER_OF_EEPROM_SECTORS_HEX_FILE      " + Convert.ToString(m_numberOfEepromSectors) + "u");
            m_swHfile.WriteLine("#define EEPROM_ROW_BYTE_SIZE_HEX_FILE      " + Convert.ToString(BYTES_PER_EEPROM_ROW) + "u");                        

            /* Defines for other memory regions, data */
            m_swHfile.WriteLine("#define NUMBER_OF_FLASH_ARRAYS_HEX_FILE      " + Convert.ToString(m_numberOfFlashArrays) + "u");
            m_swHfile.WriteLine("#define NUMBER_OF_FLASH_ROWS_HEX_FILE        " + Convert.ToString(m_numberOfFlashRows) + "u");
            m_swHfile.WriteLine("#define FLASH_ROW_BYTE_SIZE_HEX_FILE         " + Convert.ToString(m_bytesPerFlashRow) + "u");
            m_swHfile.WriteLine("#define FLASH_PROTECTION_BYTE_SIZE_HEX_FILE  " + Convert.ToString(m_numberOfFlashRows / FLASH_ROWS_PER_PROTECTION_BYTE) + "u");
            m_swHfile.WriteLine("#define DEVICE_CFG_NVL_BYTE_SIZE_HEX_FILE    " + Convert.ToString(DEVICE_CFG_NVL_BYTE_LENGTH) + "u");
            m_swHfile.WriteLine("#define WO_NVL_BYTE_SIZE_HEX_FILE            " + Convert.ToString(WO_NVL_BYTE_LENGTH) + "u");
            m_swHfile.WriteLine("#define CHECKSUM_BYTE_SIZE_HEX_FILE          " + Convert.ToString(CHECKSUM_BYTE_LENGTH) + "u");
            m_swHfile.WriteLine("#define SILICON_ID_BYTE_SIZE_HEX_FILE        " + Convert.ToString(SILICON_ID_BYTE_LENGTH) + "u");
            m_swHfile.WriteLine();

            if (m_numberOfEepromRows != 0)
            {
                headerFileTrailer = " /***************************************************************************** \n" +
                           " * Global Constant Declarations \n" +
                           "  ******************************************************************************/ \n \n" +
                           "extern unsigned char const deviceRevisionId_hexFile; \n" +
                           "extern unsigned char const deviceSiliconId_hexFile[SILICON_ID_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const deviceConfigNvl_hexFile[DEVICE_CFG_NVL_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const writeOnceNvl_hexFile[WO_NVL_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const checksumData_hexFile[CHECKSUM_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const eepromData_hexFile[NUMBER_OF_EEPROM_ROWS_HEX_FILE][EEPROM_ROW_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const flashData_hexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE][FLASH_ROW_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const flashProtectionData_hexFile[FLASH_PROTECTION_BYTE_SIZE_HEX_FILE]; \n \n" +
                           "#endif /* __HEXIMAGE_H */ \n \n" +
                           "/* [] END OF FILE */ \n";
            }
            else
            {
                headerFileTrailer = " /***************************************************************************** \n" +
                           " * Global Constant Declarations \n" +
                           "  ******************************************************************************/ \n \n" +
                           "extern unsigned char const deviceRevisionId_hexFile; \n" +
                           "extern unsigned char const deviceSiliconId_hexFile[SILICON_ID_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const deviceConfigNvl_hexFile[DEVICE_CFG_NVL_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const writeOnceNvl_hexFile[WO_NVL_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const checksumData_hexFile[CHECKSUM_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const flashData_hexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE][FLASH_ROW_BYTE_SIZE_HEX_FILE]; \n" +
                           "extern unsigned char const flashProtectionData_hexFile[FLASH_PROTECTION_BYTE_SIZE_HEX_FILE]; \n \n" +
                           "#endif /* __HEXIMAGE_H */ \n \n" +
                           "/* [] END OF FILE */ \n";
            }

            m_swHfile.Write(headerFileTrailer);
        }
        
    }
}
