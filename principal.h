#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionGuardar_triggered();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_actionNuevo_triggered();

    void on_pushButton_clicked();

private:
    Ui::Principal *ui;
    QPixmap m_lienzo;
    QPen pincel;
    QPainter *painter;
    int m_nota1;
    int m_nota2;
    int m_nota3;
    int boton;
    int x = 50;
    int y = 50;

    void dibujar();
};
#endif // PRINCIPAL_H
