#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QMovie>

namespace Ui {
class StartWidget;
}

/**
 * @class StartWidget
 * @brief Represents the main starting screen widget for the application.
 *
 * The StartWidget class provides a user interface for navigating to different sections of the application, such as
 * the learning section, quiz section, and results view.
 */
class StartWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the StartWidget class.
     * @param parent The parent QWidget, if any. Default is nullptr.
     */
    explicit StartWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the StartWidget class.
     */
    ~StartWidget();

signals:
    /**
     * @brief Signal emitted when the learn button is clicked.
     */
    void learnButtonClicked();

    /**
     * @brief Signal emitted when the quiz button is clicked.
     */
    void quizButtonClicked();

    /**
     * @brief Signal emitted when the results button is clicked.
     */
    void resultsButtonClicked();

private:
    Ui::StartWidget *ui; // Pointer to the UI components managed by Qt Designer.
    QMovie *gif; // Pointer to a QMovie object for displaying an animated GIF.
};

#endif // STARTWIDGET_H

