#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text_from_field = ui->textEdit->toPlainText();
    string text_to_file = text_from_field.toStdString();
    string file_name = "file.txt";
    ofstream out_file;
    out_file.open(file_name);
    out_file << text_to_file << endl;
    out_file.close();
    ui->label_3->setText(text_from_field);

    ifstream in_file;
    in_file.open(file_name);
    string read_file;
    int tmp_num;
    string tmp_time;
    string tmp_dest;

    int check_h, check_m;
    char ch;
    delete[] array;
    array = nullptr;
    try{
        while(getline(in_file, read_file))
        {
            istringstream ios(read_file);
            ios >> tmp_num >> tmp_dest >> tmp_time;
            istringstream ios_2(tmp_time);
            ios_2 >> check_h >> ch >> check_m;
            if((check_h < 0 || check_h > 24)||(check_m < 0 || check_m > 60))
                throw incorrect_date_input();
            add_race_to_array(Trains(tmp_num, tmp_dest, tmp_time));
        }
        for(int i = 0; i < size; i++)
        {
            cout << i + 1 << " train:\n";
            cout << "Number: " << array[i].get_number() << endl;
            cout << "Dest: " << array[i].get_dest() << endl;
            cout << "Time: " << array[i].get_time() << endl;
        }
        in_file.close();
    }
    catch(incorrect_date_input)
    {
        QMessageBox::warning(nullptr, "Увага", "Некоректно введений час, спробуйте ще раз!");
    }
}


void MainWindow::add_race_to_array(Trains race)
{
    if(array == nullptr)
    {
        size = 0;
        array = new Trains[size + 1];
        array[size] = race;
        size++;
    }
    else{
        Trains* new_array = new Trains[size + 1];
        for(int i = 0; i < size; i++)
            new_array[i] = array[i];
        new_array[size] = race;
        delete[] array;
        size++;
        array = new Trains[size + 1];
        for(int i = 0; i < size; i++)
            array[i] = new_array[i];
        delete[]new_array;
    }
}

Trains MainWindow::define_biggest_race()
{
    Trains result = array[0];
    for(int i = 0; i < size; i++)
        if(result < array[i])
            result = array[i];
    return result;
}

void MainWindow::display_biggest_race(Trains race)
{
    QString number = QString::fromStdString(to_string(race.get_number()));
    QString dest = QString::fromStdString(race.get_dest());
    QString time = QString::fromStdString(race.get_time());
    QString space = QString::fromStdString(" ");
    ui->label_5->setText(number + space + dest + space + time);
}

void MainWindow::on_pushButton_2_clicked()
{
    try{
        if(array != nullptr)
            display_biggest_race(define_biggest_race());
        else
            throw empty_array();
    }
    catch(empty_array)
    {
        QMessageBox::warning(nullptr, "Увага", "Ви не ввели жодного рейсу!");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
     ui->label_3->setText("");
     ui->label_5->setText("");
     ui->textEdit->setText("");
}

