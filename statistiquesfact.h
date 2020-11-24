#ifndef STATISTIQUESFACT_H
#define STATISTIQUESFACT_H

#include <QWidget>
#include<QtCharts/QtCharts>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include "facture.h"
namespace Ui {
class statistiquesFact;
}

class statistiquesFact : public QWidget
{
    Q_OBJECT

public:
    explicit statistiquesFact(QWidget *parent = nullptr);
    ~statistiquesFact();

private:
    Ui::statistiquesFact *ui;
    facture f;
};

#endif // STATISTIQUESFACT_H
