#ifndef BYTECONVERTERDIALOG_H_
#define BYTECONVERTERDIALOG_H_

#include <QDialog>
#include "ui_ByteConverterDialog.h"

class QLineEdit;

// Intentamos heredar las propiedades del dialogo, cuidado con el orden
class ByteConverterDialog : public QDialog, 
                            private Ui::ByteConverterDialog

{
	Q_OBJECT
	
public:
    ByteConverterDialog(QWidget *parent = 0); //Constructor de la clade

private slots:
	// Utilizando autoconnect, se recomienda solo para clases del Designer
	// ya que se inician mediante la llamada setupUi()
    void on_decChanged_textChanged(const QString&);
    void on_hexChanged_textChanged(const QString&);
    void on_binChanged_textChanged(const QString&);
    
}; //Termina la definición de la clase.

#endif /*BYTECONVERTERDIALOG_H_*/
