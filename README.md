# pszt-magazyn
Aby skompilować projekt wymagane jest posiadanie:
1. kompilator C++ (GCC 5.2.0)
2. Qt (5.5)
3. boost (1.59) - sluzy do kompilacji testow na razie
4. doxygen (1.8.10)
5. cmake (3.3.2)

W nawiasach podane wersje, których sam używam. Wszystko w miare szybko i wygodnie można pobrać za pomoca (https://msys2.github.io/)
Po zainstalowaniu odpowiedniej wersji nalezy wykonac nastepujace polecenia (przyklad dla wersji 64-bit):
1. update-core
2. uruchamiamy ponownie, jezeli cos zostalo zainstalowane
3. pacman -Su
4. pacman -S mingw-w64-x86_64-toolchain
5. pacman -S mingw-w64-x86_64-boost
6. pacman -S mingw-w64-x86_64-qt5 mingw-w64-x86_64-qt-creator
7. pacman -S mingw-w64-x86_64-doxygen 
8. pacman -S mingw-w64-x86_64-cmake 
4-8 mozna polaczyc w jedno polecenie :)
