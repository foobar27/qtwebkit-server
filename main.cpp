#include <iostream>

#include <QApplication>
#include<QUrl>
#include <thumbnailer.hpp>
#include <sexprenderer.hpp>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QUrl url("http://www.golem.de/news/cast-ar-gefeuerte-valve-entwickler-zeigen-raeumliche-objekte-brille-1305-99338.html");

    SexpRenderer renderer(url);
    // Thumbnailer renderer(url);
    app.connect(&renderer, SIGNAL(finished()), &app, SLOT(quit()));

    return app.exec();
}

