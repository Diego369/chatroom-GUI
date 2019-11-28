#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
namespace Ui {
class ChatWidget;
}

class QDESIGNER_WIDGET_EXPORT ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    ~ChatWidget();

private:
    Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
