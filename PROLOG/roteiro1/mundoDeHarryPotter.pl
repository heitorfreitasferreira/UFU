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
% ex.6
  % ?- feiticeiro(harry)
  % |    .
  % ERROR: Unknown procedure: feiticeiro/1 (DWIM could not correct goal)
%ex.7
  % ?- magico(feiticeiro).
  % ERROR: Unknown procedure: feiticeiro/1
  % ERROR: In:
  % ERROR:   [11] feiticeiro(feiticeiro)
  % ERROR:   [10] magico(feiticeiro) at /home/heitor/repositorios/UFU/PROLOG/roteiro1/mundoDeHarryPotter.pl:6
  % ERROR:    [9] <user>
  %  Exception: (11) feiticeiro(feiticeiro) ? creep
  %  Exception: (10) magico(feiticeiro) ? creep
% ex.8
  % ?- magico('McGonagall').
  % ERROR: Unknown procedure: feiticeiro/1
  % ERROR: In:
  % ERROR:   [11] feiticeiro('McGonagall')
  % ERROR:   [10] magico('McGonagall') at /home/heitor/repositorios/UFU/PROLOG/roteiro1/mundoDeHarryPotter.pl:6
  % ERROR:    [9] <user>
  %    Exception: (11) feiticeiro('McGonagall') ? 
% ex.9
  % ?- magico(hermione).
  % ERROR: Unknown procedure: feiticeiro/1
  % ERROR: In:
  % ERROR:   [11] feiticeiro(hermione)
  % ERROR:   [10] magico(hermione) at /home/heitor/repositorios/UFU/PROLOG/roteiro1/mundoDeHarryPotter.pl:6
  % ERROR:    [9] <user>
  %   Exception: (11) feiticeiro(hermione) ? 