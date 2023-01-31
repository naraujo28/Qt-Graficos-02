#include "principal.h"
#include "ui_principal.h"


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    m_lienzo =  QPixmap(500,500);
    m_lienzo.fill(Qt::white);
    this->dibujar();
    ui->outCuadro->setPixmap(m_lienzo);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    m_lienzo.fill(Qt::white);
    QPainter painter(&m_lienzo);
    int tam1 = m_nota1;
    int tam2 = m_nota2;
    int tam3 = m_nota3;

    // Crear un pincel para los bordes
    pincel.setWidth(5);
    pincel.setColor(Qt::magenta);
    pincel.setStyle(Qt::SolidLine);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setBrush(Qt::white);

    // Dibujar primera barra
    painter.drawRect(x, y+(400-tam1),100,tam1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
    QColor colorBorde(78,3,48);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    // Dibujar segunda barra
    painter.drawRect(x+150, y+(400-tam2), 100, tam2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Dibujar tercera barra
    painter.drawRect(x+300,y+(400-tam3),100,tam3);

    int y=0;
    int x=30;

    //QPainter p;
    int num = 400;
    pincel.setWidth(2);
    pincel.setColor(Qt::red);
    painter.setPen(pincel);

    for(int i =50;i<450;i +=50 ){
        painter.drawLine(x-5,i,x+5,i);
        QString linea=
        QString::number(num);
        num-=50;
        painter.drawText(x-20,i,linea);
    }
    //Dibuja linea vertical
    painter.drawLine(x,y-10,x,y+456);
    //Dibuja linea horizontal
    painter.drawLine(x+5,y+456,x+500,y+456);

    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (m_lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_spinBox_valueChanged(int arg1)
{
    m_nota1 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(m_lienzo);
}

void Principal::on_spinBox_2_valueChanged(int arg1)
{
    m_nota2 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_spinBox_3_valueChanged(int arg1)
{
    m_nota3 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_actionNuevo_triggered()
{
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->outCuadro->clear();
    m_lienzo.fill(Qt::white);
    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_pushButton_clicked()
{
    QPainter painter(&m_lienzo);
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setStyle(Qt::DashLine);
    painter.setPen(pincel);

    int promedio;

    promedio = (m_nota1 + m_nota2 + m_nota3)/3;

    painter.drawLine(30,y+(400-promedio),500,y+(400-promedio));
    ui->outCuadro->setPixmap(m_lienzo);
    ui->statusbar->showMessage("El promedio es: " + QString::number(promedio));
}

