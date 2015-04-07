#ifndef EDITMAPWINDOW_H
#define EDITMAPWINDOW_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"

namespace Ui {
class EditMapWindow;
}

class EditMapWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditMapWindow(Map* map, QWidget *parent = 0);
    ~EditMapWindow();

private slots:
    void on_obstacleButton_clicked();

    void on_saveMapButton_clicked();

private:
    Ui::EditMapWindow *ui;
    Qt::GlobalColor getColorById(int id);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent * event);
    bool mousePressed;
    Map *map;
    int selected = 0;
    int x = 0;
    int y = 0;
    int objectx = 0;
    int objecty = 0;
    int mapHeight = 0;
    int mapWidth = 0;
    int drawWidth = 430;
    int drawHeight = 460;
    vector<vector< int > > mapLayout = map->getMapContent();
};

#endif // EDITMAPWINDOW_H
