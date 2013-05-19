#pragma once

#include <QWebPage>

class SexpRenderer : public QObject
{
    Q_OBJECT

public:
    SexpRenderer(const QUrl &url);

signals:
    void finished();

private slots:
    void render();

private:
    QWebPage page;

};
