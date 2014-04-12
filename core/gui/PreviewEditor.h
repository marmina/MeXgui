#ifndef PREVIEWEDITOR_H
#define PREVIEWEDITOR_H

#include <QWidget>
#include <Phonon>
#include <QString>

namespace Ui {
class PreviewEditor;
}

class PreviewEditor : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewEditor(QWidget *parent = 0);
    ~PreviewEditor();
    void videoFile(QString filepath);

private slots:
    void on_Play_clicked();
    void on_Wind_pressed();
    void on_Wind_clicked();
    void on_ReWind_pressed();
    void on_ReWind_clicked();

private:
    QString MediaPath;
    Phonon::MediaObject *media;
    Phonon::AudioOutput *audio;
    Ui::PreviewEditor *ui;
};

#endif // PREVIEWEDITOR_H