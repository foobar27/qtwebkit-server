#include <iostream>

#include <handlers/Thumbnailer.hpp>
#include <handlers/SexpRenderer.hpp>

#include <QApplication>
#include <QUrl>
#include <QNetworkAccessManager>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QNetworkAccessManager manager(&app);
    QUrl url("http://www.golem.de/news/cast-ar-gefeuerte-valve-entwickler-zeigen-raeumliche-objekte-brille-1305-99338.html");

    SexpRenderer renderer(&manager, url);
    // Thumbnailer renderer(url);
    app.connect(&renderer, SIGNAL(finished()), &app, SLOT(quit()));

    return app.exec();
}

