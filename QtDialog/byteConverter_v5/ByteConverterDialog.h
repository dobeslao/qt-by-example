#ifndef BYTECONVERTERDIALOG_H_
#define BYTECONVERTERDIALOG_H_

#include <QDialog>
#include "ui_ByteConverterDialog.h"

// Intentamos heredar las propiedades del dialogo, cuidado con el orden
class ByteConverterDialog : public QDialog, 
                            private Ui::ByteConverterDialog
{
	Q_OBJECT
	
public:
    ByteConverterDialog(QWidget *parent = 0); //Constructor de la clade
    
}; //Termina la definición de la clase.

#endif /*BYTECONVERTERDIALOG_H_*/
