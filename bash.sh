cd  #idz do /home
ls #wyswietl
./file.ext #uruchom
chmod 777 file.ext #nadaj wszystkie uprawnienia
ps -a #pokaz procesy
kill 777777 #zakoncz proces o id 777777
su user #zmien uzytkownika na USER
su #zmieni na ROOT
echo teskt #wyswietl tekst
echo text >> file.ext #dodaj linijke text do file.ext
cat file.ext #wyswietl plik
vim file.ext #edytuje plik
clear #czysci konsole
reboot #reset
gcc file.c -o run #kompiluje file.c do pliku run
touch file.ext #tworzy nowy plik
mkdir #tworzy katalog
rm -r katalog #usuwa caly katalog
cd ../ #katalog wyzej
cd / #idz do root
whoami #podaj nazwe uzytkownika
rm * #usun wszystkie pliki z katalogu
chmod 0 file.ext #zablokuj plik
man program #wyswietla dokumentacje programu
echo -e #Pomija nawiasy itd
find *.ext #wyswietle wszytkie pliki z katalogu o rozszerzeniu .ext
pwd #podaje obecna sciezke
# CTRL + C #zatrzymaj program
cal #pokaz kalendarz
date #pokaz date
cat file.ext | grep wyraz #pokazuje liniji w ktorych jest "wyraz" i podkresla
ps -a | grep firefox #pokazuje id procesu firefox
ssh user@ip #ssh

screen -list #wyswietla ekrany
screen -X -S 123456 quit #zamyka ekran i procesy
screen # uruchamia screen
screen -r 123456 #podlaczyc ekran
#CTRL+a d #odlacz
screen -S nazwa #tworzy ekran o nazwie

