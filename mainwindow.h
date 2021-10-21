#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <stack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    double pix_to_complex_y(int y);
    double pix_to_complex_x(int x);
    QColor find_color(int x, int y);
    void updateImage();
    const double inf = 50;
    const int heigh = 500, width = 500;
    int koef = 1;
    int  index = 0;
    //std::vector<double> xl = {-1.6}, yl = {1.6}, xr = {1.6}, yr = {-1.6};
    //int xl = -2, yl = 2, xr = 2, yr = -2;
    std::stack<double> xl, yl, xr, yr;
    int x_1, y_1, x_2, y_2;
    double nx_1, nx_2, ny_1, ny_2;

private slots:
    //void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    //void on_pushButton_3_clicked();

    void on_pushButton_up_clicked();

    void on_pushButton_low_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
