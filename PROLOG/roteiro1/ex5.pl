elfo_domestico(dobby).
bruxo(hermione).
bruxo('McGonagall').
bruxo(rita_skeeter).
magico(X):- elfo_domestico(X).
% magico(X):- feiticeiro(X).
magico(X):- bruxo(X).
% ex.5
  % magico(elfo_domestico).
  % ERROR: Unknown procedure: feiticeiro/1
  % ERROR: In:
  % ERROR:   [11] feiticeiro(elfo_domestico)
  % ERROR:   [10] magico(elfo_domestico) at /home/heitor/repositorios/UFU/PROLOG/roteiro1/mundoDeHarryPotter.pl:6
  % ERROR:    [9] <user>
  %    Exception: (11) feiticeiro(elfo_domestico) ? creep
  %    Exception: (10) magico(elfo_domestico) ? abort
  % % Execution Aborted