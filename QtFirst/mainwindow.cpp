#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnePushed()
{
    expression.append("1");
    ui->expressionOutput->setText(expression);
}

void MainWindow::TwoPushed()
{
    expression.append("2");
    ui->expressionOutput->setText(expression);
}

void MainWindow::ThreePushed()
{
    expression.append("3");
    ui->expressionOutput->setText(expression);
}

void MainWindow::FourPushed()
{
    expression.append("4");
    ui->expressionOutput->setText(expression);
}

void MainWindow::FivePushed()
{
    expression.append("5");
    ui->expressionOutput->setText(expression);
}

void MainWindow::SixPushed()
{
    expression.append("6");
    ui->expressionOutput->setText(expression);
}

void MainWindow::SevenPushed()
{
    expression.append("7");
    ui->expressionOutput->setText(expression);
}

void MainWindow::EightPushed()
{
    expression.append("8");
    ui->expressionOutput->setText(expression);
}

void MainWindow::NinePushed()
{
    expression.append("9");
    ui->expressionOutput->setText(expression);
}

void MainWindow::ZeroPushed()
{
    expression.append("0");
    ui->expressionOutput->setText(expression);
}

void MainWindow::DotPushed()
{
    if (expression.indexOf('.') == -1) {
        if (expression.isEmpty()) {
            expression.append("0");
        }
        expression.append(".");
        ui->expressionOutput->setText(expression);
    }
}

void MainWindow::ChangeSign()
{
    if (expression.left(1)!='-') {
        expression.insert(0,'-');
    } else {
        expression.remove(0,1);
    }
    ui->expressionOutput->setText(expression);
}

void MainWindow::Addition()
{
    operation = '+';
    operatorPushed = true;
    firstNumber = MainWindow::ReadNumber();
}

void MainWindow::Subtraction()
{
    operation = '-';
    operatorPushed = true;
    firstNumber = MainWindow::ReadNumber();
}

void MainWindow::Multiplication()
{
    operation = '*';
    operatorPushed = true;
    firstNumber = MainWindow::ReadNumber();
}

void MainWindow::Devision()
{
    operation = '/';
    operatorPushed = true;
    firstNumber = MainWindow::ReadNumber();
}

void MainWindow::Sqroot()
{
    firstNumber = MainWindow::ReadNumber();
    result = qSqrt(firstNumber);
    expression = QString::number(result);
    ui->expressionOutput->setText(expression);
}

void MainWindow::Inverse()
{
    firstNumber = MainWindow::ReadNumber();
    result = 1.0/firstNumber;
    expression = QString::number(result);
    ui->expressionOutput->setText(expression);
}

void MainWindow::Power()
{
    operation = '^';
    operatorPushed = true;
    firstNumber = MainWindow::ReadNumber();
}

void MainWindow::Percent()
{
    QString read = ui->expressionOutput->text();
    expression.clear();
    float percent = firstNumber * ( read.toFloat() / 100.0);
    expression = QString::number(percent);
    ui->expressionOutput->setText(expression);
}

float MainWindow::DoOperation()
{
    switch(operation)  {
    case '+':
        result = firstNumber + secondNumber;
        break;
    case '-':
        result = firstNumber - secondNumber;
        break;
    case '*':
        result = firstNumber * secondNumber;
        break;
    case '/':
        result = firstNumber / secondNumber;
        break;
    case '^':
        result = qPow(firstNumber, secondNumber);
        break;
    }
    return result;
}

float MainWindow::ReadNumber()
{
    QString read = ui->expressionOutput->text();
    expression.clear();
    return read.toFloat();
}

void MainWindow::Result()
{
    if (operatorPushed) {
        secondNumber = MainWindow::ReadNumber();
        operatorPushed = false;
    }
    result = MainWindow::DoOperation();
    firstNumber = result;
    expression = QString::number(result);
    ui->expressionOutput->setText(expression);
}

void MainWindow::Correct()
{
    expression.chop(1);
    ui->expressionOutput->setText(expression);
}

void MainWindow::Clear()
{
    expression.clear();
    firstNumber  = 0.0;
    secondNumber = 0.0;
    ui->expressionOutput->setText(expression);
}
