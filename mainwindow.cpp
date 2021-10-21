#include <QtGui>
#include <QtCore>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complex.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateImage();
}

void MainWindow::on_pushButton_back_clicked() //return to the previous step
{
    if (int(xl.size()) > 1) {
        xl.pop();
        xr.pop();
        yl.pop();
        yr.pop();
        updateImage();
    }
}

void MainWindow::on_pushButton_up_clicked() //improve quality
{
    if (koef < 5) {
        koef++;
        updateImage();
    }
}

void MainWindow::on_pushButton_low_clicked() //degrade quality
{
    if (koef > 1) {
        koef--;
        updateImage();
    }
}


void MainWindow::mousePressEvent(QMouseEvent *e) {
    x_1 = e->x();
    y_1 = e->y();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    x_2 = e->x();
    y_2 = e->y();
    if (x_2 < x_1) {
        std::swap(x_2, x_1);
    }
    if (y_2 < y_1) {
        std::swap(y_2, y_1);
    }                                                                                                                            if (x_2 - x_1 > y_2 - y_1) { x_2 -= (x_2 - x_1 - (y_2 - y_1)); } else { y_2 -= (y_2 - y_1 - (x_2 - x_1)); }
    if (x_1 != x_2 || y_1 != y_2) {
        nx_1 = pix_to_complex_x(x_1);
        nx_2 = pix_to_complex_x(x_2);
        ny_1 = pix_to_complex_y(y_1);
        ny_2 = pix_to_complex_y(y_2);
        xl.push(nx_1);
        xr.push(nx_2);
        yl.push(ny_1);
        yr.push(ny_2);
        ++index;
        updateImage();
    }
}

double MainWindow::pix_to_complex_x(int x) {
    if (xl.empty()) {
        xl.push(-1.6);
    }
    if (xr.empty()) {
        xr.push(1.6);
    }
    return xl.top() + (xr.top() - xl.top()) * x / width;
}

double MainWindow::pix_to_complex_y(int y) {
    if (yl.empty()) {
        yl.push(1.6);
    }
    if (yr.empty()) {
        yr.push(-1.6);
    }
    return yl.top() - (yl.top() - yr.top()) * y / heigh;
}

QColor MainWindow::find_color(int x, int y) {
    Complex c = Complex(-0.8, 0.156);
    Complex z = Complex(pix_to_complex_x(x), pix_to_complex_y(y));
    for (int i = 0; i <= 255 * koef; ++i) {
        z = (z ^ 2) + c;
        if (z.get_abs() > inf) {
            return QColor(0, i / 4 / koef, i / koef);
        }
    }
    return QColor(0, 0, 0);
}

void MainWindow::updateImage() {
    QImage image(ui->label->size(), QImage::Format_RGB32);
    for (int y = 0; y <= heigh; ++y) {
        for (int x = 0; x <= width; ++x) {
            QColor color = find_color(x, y);
            image.setPixelColor(x, y, color);
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));
}

MainWindow::~MainWindow()
{
    delete ui;
}
