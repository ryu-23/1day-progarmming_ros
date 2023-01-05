import sys
#from PyQt5.QtWidgets import QApplication, QWidget,QSpinBox,QTabWidget,QGridLayout ,QPushButton, QVBoxLayout, QLabel, QCheckBox, QLineEdit, QRadioButton
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import *

class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        ###########################################

        resultTable = QTableWidget(self)
        resultTable.setRowCount(5)
        resultTable.setColumnCount(5)

        resultTable.setEditTriggers(QAbstractItemView.AllEditTriggers)
        resultTable.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeToContents)
        resultTable.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        resultTable.move(60, 380)





        ###########################################

        spinbox = QSpinBox(self)
        lblspin = QLabel('PWM',self)
        spinbox.setMinimum(-255)
        spinbox.setMaximum(255)
        # self.spinbox.setRange(-10, 30)
        spinbox.setSingleStep(5)

        spinbox.move(50, 32)
        lblspin.move(10,36)


        ###########################################
        rbtn1 = QRadioButton('MOTOR_ON', self)
        rbtn1.move(50, 300)
        rbtn1.setChecked(True)

        rbtn2 = QRadioButton(self)
        rbtn2.move(50, 320)
        rbtn2.setText("MOTOR_OFF")


        label1 = QLabel('PORPOSE', self)
        label1.move(120, 60)

        label2 = QLabel('MAKE MOTOE CONTROLLER', self)
        label2.move(100, 100)

        label3 = QLabel('P', self)
        label3.move(50, 250)

        label4 = QLabel('PI', self)
        label4.move(140, 250)

        label5 = QLabel('PD', self)
        label5.move(230, 250)

        font1 = label1.font()
        font1.setPointSize(20)

        font2 = label2.font()
        font2.setFamily('Times New Roman')
        font2.setBold(True)

        label1.setFont(font1)
        label2.setFont(font2)

        btn1 = QPushButton('&P', self)
        btn1.move(30, 150)



        btn2 = QPushButton(self)
        btn2.move(30, 180)
        btn2.setText('PI&')

        btn3 = QPushButton('PD', self)
        btn3.move(30, 210)
        btn3.setEnabled(True)


        cb = QCheckBox('Show title', self)
        cb.move(10, 10)
        cb.toggle()
        cb.stateChanged.connect(self.changeTitle)

        self.lbl = QLabel(self)
        self.lbl.move(80, 250)

        qle = QLineEdit(self)
        qle.move(140, 150)
        qle.textChanged[str].connect(self.onChanged)

        self.lbl2 = QLabel(self)
        self.lbl2.move(170, 250)

        qle2 = QLineEdit(self)
        qle2.move(140, 180)
        qle2.textChanged[str].connect(self.onChanged2)

        self.lbl3 = QLabel(self)
        self.lbl3.move(260, 250)

        qle3 = QLineEdit(self)
        qle3.move(140, 210)
        qle3.textChanged[str].connect(self.onChanged3)

        self.setWindowTitle('MOTOE CONTROLLER')
        self.setGeometry(350, 350, 350, 700)
        self.show()

    def changeTitle(self, state):
        if state == Qt.Checked:
            self.setWindowTitle('MOTOE CONTROLLER')
        else:
            self.setWindowTitle(' ')

    def onChanged(self, text1):
        self.lbl.setText(text1)
        self.lbl.adjustSize()

    def onChanged2(self, text):
        self.lbl2.setText(text)
        self.lbl2.adjustSize()

    def onChanged3(self, text):
        self.lbl3.setText(text)
        self.lbl3.adjustSize()

    def value_changed(self):
        self.lbl2.setText(str(self.spinbox.value()))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())