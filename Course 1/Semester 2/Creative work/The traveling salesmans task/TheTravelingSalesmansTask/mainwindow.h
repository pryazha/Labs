#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "road.h"
#include "city.h"
#include "solution.h"
#include "mygraphicsscene.h"

#include <vector>
#include <QMainWindow>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_city();
    void start_road_creation1();
    void start_road_creation2();
    void choose_city(City*);
    void showSolution();
    void city_numeration(std::vector<int>);
    void process_selection(QGraphicsItem*);

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    myGraphicsScene* scene;
    std::vector<City*> cities;
    std::vector<Road*> roads;
    City* chosen_city;
    QDoubleValidator m_doubleValidator;
    bool double_sided;

};
#endif // MAINWINDOW_H
