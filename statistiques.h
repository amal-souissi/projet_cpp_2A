#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QWidget>

#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>

#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include<QGridLayout>
#include"grade.h"

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class statistiques;
}

class statistiques : public QWidget
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();

private:
    Ui::statistiques *ui;
    grade tmpgrade;
};

#endif // STATISTIQUES_H
