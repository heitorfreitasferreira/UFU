elfo_domestico(dobby).
bruxo(hermione).
bruxo('McGonagall').
bruxo(rita_skeeter).
magico(X):- elfo_domestico(X).
% magico(X):- feiticeiro(X).
magico(X):- bruxo(X).
% ex.9
  % ?- magico(hermione).
  % ERROR: Unknown procedure: feiticeiro/1
  % ERROR: In:
  % ERROR:   [11] feiticeiro(hermione)
  % ERROR:   [10] magico(hermione) at /home/heitor/repositorios/UFU/PROLOG/roteiro1/mundoDeHarryPotter.pl:6
  % ERROR:    [9] <user>
  %   Exception: (11) feiticeiro(hermione) ? 