# PhoneGames 🎮

[English](#english) | [Türkçe](#türkçe)

---

## English

**PhoneGames** is a collection of console-based mini-games developed in C. This project features a player progression system where users can earn points, level up, and save their stats.

### 🚀 Features
* **User System:** Create a character with a name, earn points, and level up based on your performance.
* **Save/Load:** Your progress (points and level) is saved to a `stats.txt` file, allowing you to continue later.
* **Platform:** Designed for Windows (uses `<windows.h>` and `<conio.h>`).

### 🕹️ Games Included

#### 1. Minefield (Not Minesweeper!)
A strategic game where the goal is to **find** the mines, rather than avoid them.
* **Objective:** Reveal all hidden mines on the grid without running out of lives.
* **Difficulty Levels:**
    * **Easy:** 9x9 Grid (10 Mines)
    * **Medium:** 16x16 Grid (40 Mines)
    * **Hard:** 30x16 Grid (99 Mines)
* **Mechanics:** You have 3 lives. Unlike classic Minesweeper, you want to hit the mines to collect them!

#### 2. Snake Game 🐍
The classic arcade experience.
* **Customizable Area:** Choose your own board size (between 8x8 and 40x40).
* **Controls:** Use `W`, `A`, `S`, `D` to move.
* **Objective:** Eat the food (displayed as `8`), grow your snake, and avoid hitting walls or your own tail.

### 🛠️ Installation & How to Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/ardaakman1/PhoneGames.git](https://github.com/ardaakman1/PhoneGames.git)
    ```
2.  **Compile the code:**
    You need a C compiler (like GCC). Since this project uses Windows-specific libraries, please run it on a Windows machine.
    ```bash
    gcc phonegames.c -o phonegames.exe
    ```
3.  **Run the game:**
    ```bash
    phonegames.exe
    ```

### 📂 Project Structure
* `phonegames.c`: Main entry point, handles the menu and user data.
* `games/game1.h`: Source code for the Minefield game.
* `games/game2.h`: Source code for the Snake game.
* `games/menu.h`: Helper file for displaying the menu.

---

## Türkçe

**PhoneGames**, C programlama dili ile geliştirilmiş, konsol tabanlı bir mini oyun koleksiyonudur. Bu proje, kullanıcıların puan kazanabileceği, seviye atlayabileceği ve istatistiklerini kaydedebileceği bir ilerleme sistemi içerir.

### 🚀 Özellikler
* **Kullanıcı Sistemi:** Bir karakter oluşturun, oyunlardan puan toplayın ve seviye atlayın.
* **Kaydet/Yükle:** İlerlemeniz (puanlar ve seviye) `stats.txt` dosyasına kaydedilir, böylece oyuna daha sonra kaldığınız yerden devam edebilirsiniz.
* **Platform:** Windows işletim sistemi için tasarlanmıştır (`<windows.h>` ve `<conio.h>` kütüphanelerini kullanır).

### 🕹️ Oyunlar

#### 1. Mayın Tarlası (Minefield)
Klasik Mayın Tarlası'ndan (Minesweeper) farklı olarak, burada amaç mayınlardan kaçmak değil, onları **bulmaktır**.
* **Amaç:** Canlarınız tükenmeden haritadaki tüm gizli mayınları bulun.
* **Zorluk Seviyeleri:**
    * **Kolay:** 9x9 Alan (10 Mayın)
    * **Orta:** 16x16 Alan (40 Mayın)
    * **Zor:** 30x16 Alan (99 Mayın)
* **Mekanik:** 3 canınız vardır. Mayınları buldukça puan kazanırsınız.

#### 2. Yılan Oyunu (Snake) 🐍
Klasik yılan oyunu deneyimi.
* **Özelleştirilebilir Alan:** Oyun alanının boyutunu kendiniz belirleyebilirsiniz (8x8 ile 40x40 arası).
* **Kontroller:** Hareket etmek için `W`, `A`, `S`, `D` tuşlarını kullanın.
* **Amaç:** Yemi (`8` olarak görünür) yiyerek büyüyün, duvarlara veya kendi kuyruğunuza çarpmamaya dikkat edin.

### 🛠️ Kurulum ve Çalıştırma

1.  **Projeyi indirin:**
    ```bash
    git clone [https://github.com/ardaakman1/PhoneGames.git](https://github.com/ardaakman1/PhoneGames.git)
    ```
2.  **Kodu derleyin:**
    Bir C derleyicisine (örneğin GCC) ihtiyacınız vardır. Proje Windows kütüphanelerini kullandığı için Windows üzerinde derlemeniz gerekir.
    ```bash
    gcc phonegames.c -o phonegames.exe
    ```
3.  **Oyunu başlatın:**
    ```bash
    phonegames.exe
    ```

### 📂 Proje Yapısı
* `phonegames.c`: Ana dosya; menüyü ve kullanıcı verilerini yönetir.
* `games/game1.h`: Mayın Tarlası oyununun kaynak kodları.
* `games/game2.h`: Yılan oyununun kaynak kodları.
* `games/menu.h`: Menü ekranı için yardımcı dosya.
