# 3DViewer v2.0

Программа для визуализации каркасных 3D моделей в трехмерном пространстве.

## Описание проекта

3DViewer v2.0 - это приложение, разработанное на языке программирования C++, которое позволяет загружать и визуализировать 3D модели в каркасном виде. Программа обладает широкими возможностями для работы с моделями, включая перемещение, вращение и масштабирование. 

Проект разработан с использованием принципов объектно-ориентированного программирования и паттернов проектирования, что обеспечивает его структурную ясность и расширяемость.

## Основные функции

- Загрузка 3D моделей из файлов формата OBJ.
- Перемещение модели по осям X, Y, Z.
- Вращение модели вокруг своих осей X, Y, Z.
- Масштабирование модели.
- Настраиваемые параметры отображения, включая тип проекции, тип и стиль ребер, способ отображения вершин и цвет фона.

## Графический интерфейс

Программа обладает интуитивно понятным графическим пользовательским интерфейсом, который включает в себя:

- Кнопку выбора файла с моделью и поле для отображения имени файла.
- Зону для визуализации 3D модели.
- Элементы управления для перемещения, вращения и масштабирования модели.
- Информацию о загруженной модели, включая название файла, количество вершин и ребер.

## Производительность

3DViewer v2.0 спроектирован с учетом высокой производительности. Программа способна обрабатывать 3D модели с количеством вершин от нескольких сотен до миллионов без заметного снижения отзывчивости интерфейса.

## Настройки

- Программа предоставляет возможность настройки типа проекции (параллельная и центральная).
- Настраиваемые параметры включают тип (сплошная, пунктирная), цвет и толщину ребер, способ отображения вершин, цвет фона и размер вершин.
- Настройки сохраняются между перезапусками программы.

## Запись и экспорт

- Программа позволяет сохранять изображения моделей в файлах в форматах BMP и JPEG.
- Вы можете создавать "скринкасты" - gif-анимации, демонстрирующие аффинные преобразования загруженной модели.

## Демонстрация работы

(немного подождите, чтобы загрузились gif-анимации)

*Загрузка модели, а также ее перемещение, вращение и масштабирование*

![Скринкаст загрузки модели](misc/image/upload.gif)


*Настройка параметров отображения: тип линий (сплошная, пунктирная), цвет и толщина ребер, способ отображения вершин, цвет фона и размер вершин*

![Скринкаст настройки отображения](misc/image/settings.gif)


## Требования к сборке

- Код программы находится в папке `src`.
- Сборка осуществляется с использованием Makefile с набором стандартных целей для GNU-программ.
- Установка может быть выполнена в произвольный каталог.

## Зависимости

Программа разработана с использованием следующих библиотек и паттернов:

- Графический интерфейс - Qt, OpenGL.
- Паттерны - синглтон, фасад, стратегия.

## Установка

Ввод в терминале make install. После установки в папке build появится иконка программы.


## Автор

- Виктория (s21_utheryde)

## Благодарности


Благодарю себя и моих друзей
