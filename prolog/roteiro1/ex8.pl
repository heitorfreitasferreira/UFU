elfo_domestico(dobby).
bruxo(hermione).
bruxo('McGonagall').
bruxo(rita_skeeter).
magico(X):- elfo_domestico(X).
% magico(X):- feiticeiro(X).
magico(X):- bruxo(X).
% ex.8
  % ?- magico('McGonagall').
  % ERROR: Unknown procedure: feiticeiro/1
  % ERROR: In:
  % ERROR:   [11] feiticeiro('McGonagall')
  % ERROR:   [10] magico('McGonagall') at /home/heitor/repositorios/UFU/PROLOG/roteiro1/mundoDeHarryPotter.pl:6
  % ERROR:    [9] <user>
  %    Exception: (11) feiticeiro('McGonagall') ? 