#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "event_list_viewer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(EventListViewer *wrapper, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void setupUIConnections();
};

#endif // MAIN_WINDOW_H
