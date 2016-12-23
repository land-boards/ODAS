namespace HexFileParser_Psoc3_5lp
{
    partial class FormHexFileParser_Psoc3_5lp
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.folderBrowserDialogTargetFile = new System.Windows.Forms.FolderBrowserDialog();
            this.openFileDialogSourceHex = new System.Windows.Forms.OpenFileDialog();
            this.buttonParser = new System.Windows.Forms.Button();
            this.buttonTargetLocation = new System.Windows.Forms.Button();
            this.toolTipMessage = new System.Windows.Forms.ToolTip(this.components);
            this.textBoxTargetLocation = new System.Windows.Forms.TextBox();
            this.textBoxHexFile = new System.Windows.Forms.TextBox();
            this.buttonSourceHexFile = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // buttonParser
            // 
            this.buttonParser.Location = new System.Drawing.Point(243, 243);
            this.buttonParser.Name = "buttonParser";
            this.buttonParser.Size = new System.Drawing.Size(114, 23);
            this.buttonParser.TabIndex = 9;
            this.buttonParser.Text = "Parse Hex File";
            this.buttonParser.UseVisualStyleBackColor = true;
            this.buttonParser.Click += new System.EventHandler(this.buttonParser_Click);
            // 
            // buttonTargetLocation
            // 
            this.buttonTargetLocation.Location = new System.Drawing.Point(534, 136);
            this.buttonTargetLocation.Name = "buttonTargetLocation";
            this.buttonTargetLocation.Size = new System.Drawing.Size(28, 20);
            this.buttonTargetLocation.TabIndex = 8;
            this.buttonTargetLocation.Text = "...";
            this.buttonTargetLocation.UseVisualStyleBackColor = true;
            this.buttonTargetLocation.Click += new System.EventHandler(this.buttonTargetLocation_Click);
            // 
            // textBoxTargetLocation
            // 
            this.textBoxTargetLocation.Location = new System.Drawing.Point(118, 136);
            this.textBoxTargetLocation.Name = "textBoxTargetLocation";
            this.textBoxTargetLocation.Size = new System.Drawing.Size(398, 20);
            this.textBoxTargetLocation.TabIndex = 7;
            this.textBoxTargetLocation.MouseHover += new System.EventHandler(this.textBoxTargetLocation_MouseHover);
            // 
            // textBoxHexFile
            // 
            this.textBoxHexFile.Location = new System.Drawing.Point(118, 29);
            this.textBoxHexFile.Name = "textBoxHexFile";
            this.textBoxHexFile.Size = new System.Drawing.Size(398, 20);
            this.textBoxHexFile.TabIndex = 6;
            this.textBoxHexFile.MouseHover += new System.EventHandler(this.textBoxHexFile_MouseHover);
            // 
            // buttonSourceHexFile
            // 
            this.buttonSourceHexFile.Location = new System.Drawing.Point(534, 29);
            this.buttonSourceHexFile.Name = "buttonSourceHexFile";
            this.buttonSourceHexFile.Size = new System.Drawing.Size(28, 20);
            this.buttonSourceHexFile.TabIndex = 5;
            this.buttonSourceHexFile.Text = "...";
            this.buttonSourceHexFile.UseVisualStyleBackColor = true;
            this.buttonSourceHexFile.Click += new System.EventHandler(this.buttonSourceHexFile_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Control;
            this.textBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox1.Location = new System.Drawing.Point(22, 32);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(52, 13);
            this.textBox1.TabIndex = 10;
            this.textBox1.Text = "Hex File:";
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.SystemColors.Control;
            this.textBox2.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox2.Location = new System.Drawing.Point(22, 139);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(90, 13);
            this.textBox2.TabIndex = 11;
            this.textBox2.Text = "Target File Folder:";
            // 
            // FormHexFileParser_Psoc3_5lp
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(584, 412);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.buttonParser);
            this.Controls.Add(this.buttonTargetLocation);
            this.Controls.Add(this.textBoxTargetLocation);
            this.Controls.Add(this.textBoxHexFile);
            this.Controls.Add(this.buttonSourceHexFile);
            this.Name = "FormHexFileParser_Psoc3_5lp";
            this.Text = "Hex File Parser PSoC3_5LP";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialogTargetFile;
        private System.Windows.Forms.OpenFileDialog openFileDialogSourceHex;
        private System.Windows.Forms.Button buttonParser;
        private System.Windows.Forms.Button buttonTargetLocation;
        private System.Windows.Forms.ToolTip toolTipMessage;
        private System.Windows.Forms.TextBox textBoxTargetLocation;
        private System.Windows.Forms.TextBox textBoxHexFile;
        private System.Windows.Forms.Button buttonSourceHexFile;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
    }
}

