#include "statistiques.h"
#include "ui_statistiques.h"

statistiques::statistiques(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);

    QBarSet *set1=new QBarSet("Nombre des employes");


    set1->append(tmpgrade.nombreEmp());
    QBarSeries *series=new QBarSeries();
    series->append(set1);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("statistiques des employes");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories=tmpgrade.listStatuts();

    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartview=new QChartView(chart);

    QGridLayout *mainLayout=new QGridLayout();
    mainLayout->addWidget(chartview,0,0);
    this->setLayout(mainLayout);
}

statistiques::~statistiques()
{
    delete ui;
}
