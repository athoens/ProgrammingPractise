#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtMath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString expression;
    bool operatorPushed = false;
    char operation;
    float firstNumber;
    float secondNumber;
    float result;
    float DoOperation();
    float ReadNumber();

public slots:
    // Numbers and separation
    void OnePushed();
    void TwoPushed();
    void ThreePushed();
    void FourPushed();
    void FivePushed();
    void SixPushed();
    void SevenPushed();
    void EightPushed();
    void NinePushed();
    void ZeroPushed();
    void DotPushed();
    // Read operators
    void ChangeSign();
    void Addition();
    void Subtraction();
    void Multiplication();
    void Devision();
    void Percent();
    void Sqroot();
    void Inverse();
    void Power();

    // Clear options
    void Correct();
    void Clear();

    // Produce the result
    void Result();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
