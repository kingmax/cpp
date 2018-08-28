namespace WF4Max
{
    partial class MyWindow
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.btnBox = new System.Windows.Forms.Button();
            this.btnSphere = new System.Windows.Forms.Button();
            this.btnTeapot = new System.Windows.Forms.Button();
            this.btnCylinder = new System.Windows.Forms.Button();
            this.btnDummy = new System.Windows.Forms.Button();
            this.btnPoint = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.lblStatus = new System.Windows.Forms.ToolStripStatusLabel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnBox
            // 
            this.btnBox.Location = new System.Drawing.Point(23, 23);
            this.btnBox.Name = "btnBox";
            this.btnBox.Size = new System.Drawing.Size(137, 54);
            this.btnBox.TabIndex = 0;
            this.btnBox.Text = "Box";
            this.btnBox.UseVisualStyleBackColor = true;
            this.btnBox.Click += new System.EventHandler(this.btnBox_Click);
            // 
            // btnSphere
            // 
            this.btnSphere.Location = new System.Drawing.Point(177, 23);
            this.btnSphere.Name = "btnSphere";
            this.btnSphere.Size = new System.Drawing.Size(137, 54);
            this.btnSphere.TabIndex = 1;
            this.btnSphere.Text = "Sphere";
            this.btnSphere.UseVisualStyleBackColor = true;
            this.btnSphere.Click += new System.EventHandler(this.btnSphere_Click);
            // 
            // btnTeapot
            // 
            this.btnTeapot.Location = new System.Drawing.Point(177, 100);
            this.btnTeapot.Name = "btnTeapot";
            this.btnTeapot.Size = new System.Drawing.Size(137, 54);
            this.btnTeapot.TabIndex = 3;
            this.btnTeapot.Text = "Teapot";
            this.btnTeapot.UseVisualStyleBackColor = true;
            this.btnTeapot.Click += new System.EventHandler(this.btnTeapot_Click);
            // 
            // btnCylinder
            // 
            this.btnCylinder.Location = new System.Drawing.Point(23, 100);
            this.btnCylinder.Name = "btnCylinder";
            this.btnCylinder.Size = new System.Drawing.Size(137, 54);
            this.btnCylinder.TabIndex = 2;
            this.btnCylinder.Text = "Cylinder";
            this.btnCylinder.UseVisualStyleBackColor = true;
            this.btnCylinder.Click += new System.EventHandler(this.btnCylinder_Click);
            // 
            // btnDummy
            // 
            this.btnDummy.Location = new System.Drawing.Point(177, 180);
            this.btnDummy.Name = "btnDummy";
            this.btnDummy.Size = new System.Drawing.Size(137, 54);
            this.btnDummy.TabIndex = 5;
            this.btnDummy.Text = "Dummy";
            this.btnDummy.UseVisualStyleBackColor = true;
            this.btnDummy.Click += new System.EventHandler(this.btnDummy_Click);
            // 
            // btnPoint
            // 
            this.btnPoint.Location = new System.Drawing.Point(23, 180);
            this.btnPoint.Name = "btnPoint";
            this.btnPoint.Size = new System.Drawing.Size(137, 54);
            this.btnPoint.TabIndex = 4;
            this.btnPoint.Text = "Point";
            this.btnPoint.UseVisualStyleBackColor = true;
            this.btnPoint.Click += new System.EventHandler(this.btnPoint_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(23, 259);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(291, 264);
            this.pictureBox1.TabIndex = 6;
            this.pictureBox1.TabStop = false;
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.lblStatus});
            this.statusStrip1.Location = new System.Drawing.Point(0, 534);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(336, 25);
            this.statusStrip1.TabIndex = 7;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // lblStatus
            // 
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(50, 20);
            this.lblStatus.Text = "Ready";
            // 
            // MyWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(336, 559);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.btnDummy);
            this.Controls.Add(this.btnPoint);
            this.Controls.Add(this.btnTeapot);
            this.Controls.Add(this.btnCylinder);
            this.Controls.Add(this.btnSphere);
            this.Controls.Add(this.btnBox);
            this.Name = "MyWindow";
            this.Text = "WF4Max";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel lblStatus;
        public System.Windows.Forms.Button btnBox;
        public System.Windows.Forms.Button btnSphere;
        public System.Windows.Forms.Button btnTeapot;
        public System.Windows.Forms.Button btnCylinder;
        public System.Windows.Forms.Button btnDummy;
        public System.Windows.Forms.Button btnPoint;
    }
}

