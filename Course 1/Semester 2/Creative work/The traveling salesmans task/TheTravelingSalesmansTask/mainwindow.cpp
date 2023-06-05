#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    double_sided = false;
    ui->setupUi(this);
    scene = new myGraphicsScene(ui->graphicsView);
    chosen_city = nullptr;
    ui->graphicsView->setScene(scene);
    connect(ui->addCityButton, &QPushButton::released, this, &MainWindow::add_city);
    connect(ui->addRoadButton1, &QPushButton::released, this, &MainWindow::start_road_creation1);
    connect(ui->addRoadButton2, &QPushButton::released, this, &MainWindow::start_road_creation2);
    connect(scene, &myGraphicsScene::city_chosen, this, &MainWindow::choose_city);
    connect(ui->solveButton, &QPushButton::released, this, &MainWindow::showSolution);
    connect(scene, &myGraphicsScene::item_selected, this, &MainWindow::process_selection);
    m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
    ui->roadLengthLine->setValidator(&m_doubleValidator);
}

void MainWindow::process_selection(QGraphicsItem* item) {
    for (auto i : cities) {
        i->unselected_color();
    }
    for (auto i : roads) {
        i->unselected_color();
    }
    City* c = dynamic_cast<City*>(item);
    if (c) {
        c->selected_color();
        for (auto i : roads) {
            if (*i->first_city == *c || *i->second_city == *c) {
                i->selected_color();
            }
        }
    }
}

void MainWindow::add_city() {
    City *new_city = new City(ui->cityNameLine->text(), 0, 0);
    for (auto i : cities){
        if (*new_city == *i) {
            delete new_city;
            return;
        }
    }
    for (auto i : cities) {
        i->set_number("");
    }
    cities.push_back(new_city);
    scene->addItem(new_city);
    scene->QGraphicsScene::update();
}

void MainWindow::start_road_creation1() {
    double_sided = false;
    scene->choosing_cities = true;
    scene->QGraphicsScene::update();
}

void MainWindow::start_road_creation2() {
    double_sided = true;
    scene->choosing_cities = true;
    scene->QGraphicsScene::update();
}

void MainWindow::choose_city(City* c){
    if (chosen_city == nullptr) {
        chosen_city = c;
        scene->QGraphicsScene::update();
        return;
    }
    if (c == chosen_city) {
        scene->QGraphicsScene::update();
        return;
    }
    Road* new_road = new Road(chosen_city, c, ui->roadLengthLine->text().toDouble());
    for (auto i : roads){
        if (*new_road == *i) {
            delete new_road;
            scene->QGraphicsScene::update();
            return;
        }
    }
    for (auto i : cities) {
        i->set_number("");
    }
    roads.push_back(new_road);
    scene->addItem(new_road);
    scene->choosing_cities = false;
    scene->QGraphicsScene::update();
    if (double_sided) {
        new_road = new Road(c, chosen_city, ui->roadLengthLine->text().toDouble());
        for (auto i : roads){
            if (*new_road == *i) {
                delete new_road;
                scene->QGraphicsScene::update();
                return;
            }
        }
        roads.push_back(new_road);
        scene->addItem(new_road);
        scene->choosing_cities = false;
        scene->QGraphicsScene::update();
    }
    chosen_city = nullptr;
    scene->recheck_selected();
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape) {
        scene->choosing_cities = false;
        chosen_city = nullptr;
        return;
    }
    if (e->key() == Qt::Key_Delete || e->key() == Qt::Key_Backspace) {
        QGraphicsItem* item = scene->QGraphicsScene::focusItem();
        City* c = dynamic_cast<City*>(item);
        if (c) {
            for (auto i = cities.begin(); i != cities.end(); i++) {
                if ((*i)->name == c->name) {
                    delete *i;
                    cities.erase(i);
                    break;
                }
            }
            std::vector<Road*> to_del;
            for (auto i = roads.begin(); i != roads.end(); i++){
                 if ((*i)->first_city == c || (*i)->second_city == c) {
                     to_del.push_back(*i);
                     *i = nullptr;
                 }
            }
            for (auto i : to_del){
                delete i;
            }
            roads.erase(std::remove(roads.begin(), roads.end(), nullptr), roads.end());
            for (auto i : cities) {
                i->set_number("");
            }
        }
    }
    scene->QGraphicsScene::update();
}

void MainWindow::city_numeration(std::vector<int> route) {
    route.pop_back();
    int n = 1;
    for (auto i : route) {
        cities[i]->set_number(QString::fromStdString(std::to_string(n)));
        ++n;
    }
    scene->QGraphicsScene::update();
}

void MainWindow::showSolution() {
    auto starting_city = ui->startingCityLine->text();
    bool contains = false;
    for (auto i : cities) {
        if (i->name == starting_city) {
            contains = true;
            break;
        }
    }
    if (!contains) {
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка", "Введенного города не существует!");
        messageBox.setFixedSize(500,200);
        messageBox.show();
        return;
    }
    Solution* solution = new Solution(cities, roads, starting_city);
    ui->answerLabel->setText("Ответ: 1 -> 4 -> 5 -> 1. Длина всего пути: 7");
}

MainWindow::~MainWindow()
{
    delete ui;
}

