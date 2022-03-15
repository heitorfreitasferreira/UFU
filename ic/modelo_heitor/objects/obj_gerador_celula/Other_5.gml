/// @description Insert description here
// You can write your code in this editor
var scr = [1,2,3,4,5,6,7,8,9,10]
var scr_name = ["Um","Dois","Tres","Quatro","Cinco","Seis","Sete","Oito","Nove","Dez",]
var file = file_text_open_write(working_directory + "hiscore.txt");
for (var i = 0; i < 10; ++i;)
{
    file_text_write_real(file, scr[i]);
    file_text_writeln(file);
    file_text_write_string(file, scr_name[i]);
    file_text_writeln(file);
}
file_text_close(file);