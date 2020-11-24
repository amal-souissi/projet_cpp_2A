#include "statistiquesfact.h"
#include "ui_statistiquesfact.h"

statistiquesFact::statistiquesFact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistiquesFact)
{
    ui->setupUi(this);
    QBarSet *set=new QBarSet("Nombre des factures");
    *set<<f.calculer(1)<<f.calculer(2)<<f.calculer(3)<<f.calculer(4)<<f.calculer(5)<<f.calculer(6)<<f.calculer(7)<<f.calculer(8)<<f.calculer(9)<<f.calculer(10)<<f.calculer(11)<<f.calculer(12);
    QBarSeries *series=new QBarSeries();
    series->append(set);
    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des factures");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList mois;
    mois<<"Janvier"<<"Février"<<"Mars"<<"Avril"<<"Mai"<<"Juin"<<"Juillet"<<"Aout"<<"Septembre"<<"Octobre"<<"Novombre"<<"Décembre";
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(mois);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);

    QChartView *chartview=new QChartView(chart);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartview, 0, 0);
    this->setLayout(mainLayout);


}

statistiquesFact::~statistiquesFact()
{
    delete ui;
}
