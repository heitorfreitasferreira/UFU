palavra(artigo,um).
palavra(artigo,qualquer).
palavra(nome,criminoso).
palavra(nome,'mac lanche feliz').
palavra(verbo,come).
palavra(verbo,adora).

sentenca(Palavra1,Palavra2,Palavra3,Palavra4,Palavra5) :- palavra(artigo,Palavra1),palavra(nome,Palavra2),palavra(verbo,Palavra3),palavra(artigo,Palavra4),palavra(nome,Palavra5).

% ?- sentenca(um,criminoso,adora,qualquer,'mac lanche feliz').
  % true.

% ?- sentenca(Artigo,Nome,Verbo,Artigo,Nome).
  % Artigo = um,
  % Nome = criminoso,
  % Verbo = come ;
  % Artigo = um,
  % Nome = criminoso,
  % Verbo = adora ;
  % Artigo = um,
  % Nome = 'mac lanche feliz',
  % Verbo = come ;
  % Artigo = um,
  % Nome = 'mac lanche feliz',
  % Verbo = adora ;
  % Artigo = qualquer,
  % Nome = criminoso,
  % Verbo = come ;
  % Artigo = qualquer,
  % Nome = criminoso,
  % Verbo = adora ;
  % Artigo = qualquer,
  % Nome = 'mac lanche feliz',
  % Verbo = come ;
  % Artigo = qualquer,
  % Nome = 'mac lanche feliz',
  % Verbo = adora.

%ex.11
  ?- sentenca(Artigo,Nome,Verbo,Artigo2,Nome2).
    % Artigo = Artigo2, Artigo2 = um,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = come ;
    % um criminoso come um criminoso

    % Artigo = Artigo2, Artigo2 = um,
    % Nome = criminoso,
    % Verbo = come,
    % Nome2 = 'mac lanche feliz' ;
    % um criminoso come um mac lanche feliz

    % Artigo = um,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = come,
    % Artigo2 = qualquer ;
    % um criminoso come qualquer criminoso

    % Artigo = um,
    % Nome = criminoso,
    % Verbo = come,
    % Artigo2 = qualquer,
    % Nome2 = 'mac lanche feliz' ;
    % um criminoso come qualquer mac lanche feliz

    % Artigo = Artigo2, Artigo2 = um,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = adora ;
    % um criminoso adora um criminoso

    % Artigo = Artigo2, Artigo2 = um,
    % Nome = criminoso,
    % Verbo = adora,
    % Nome2 = 'mac lanche feliz' ;
    % um criminoso adora um mac lanche feliz

    % Artigo = um,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = adora,
    % Artigo2 = qualquer ;
    % um criminoso adora qualquer criminoso

    % Artigo = um,
    % Nome = criminoso,
    % Verbo = adora,
    % Artigo2 = qualquer,
    % Nome2 = 'mac lanche feliz' ;
    % um criminoso adora qualquer mac lanche feliz

    % Artigo = Artigo2, Artigo2 = um,
    % Nome = 'mac lanche feliz',
    % Verbo = come,
    % Nome2 = criminoso ;
    % um mac lanche feliz come um criminoso

    % Artigo = Artigo2, Artigo2 = um,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = come ;
    % um mac lanche feliz come um mac lanche feliz

    % Artigo = um,
    % Nome = 'mac lanche feliz',
    % Verbo = come,
    % Artigo2 = qualquer,
    % Nome2 = criminoso ;
    % um mac lanche feliz come qualquer criminoso

    % Artigo = um,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = come,
    % Artigo2 = qualquer ;
    % um mac lanche feliz come qualquer mac lanche feliz
    
    % Artigo = Artigo2, Artigo2 = um,
    % Nome = 'mac lanche feliz',
    % Verbo = adora,
    % Nome2 = criminoso ;
    % um mac lanche feliz adora um criminoso

    % Artigo = Artigo2, Artigo2 = um,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = adora ;
    % um mac lanche feliz adora um mac lanche feliz

    % Artigo = um,
    % Nome = 'mac lanche feliz',
    % Verbo = adora,
    % Artigo2 = qualquer,
    % Nome2 = criminoso ;
    % um mac lanche feliz adora qualquer criminoso

    % Artigo = um,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = adora,
    % Artigo2 = qualquer ;
    % um mac lanche feliz adora qualquer mac lanche feliz

    % Artigo = qualquer,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = come,
    % Artigo2 = um ;
    % qualquer criminoso come um criminoso

    % Artigo = qualquer,
    % Nome = criminoso,
    % Verbo = come,
    % Artigo2 = um,
    % Nome2 = 'mac lanche feliz' ;
    % qualquer criminoso come um mac lanche feliz

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = come ;
    % qualquer criminoso come qualquer criminoso

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = criminoso,
    % Verbo = come,
    % Nome2 = 'mac lanche feliz' ;
    % qualquer criminoso come qualquer mac lanche feliz

    % Artigo = qualquer,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = adora,
    % Artigo2 = um ;
    % qualquer criminoso adora um criminoso

    % Artigo = qualquer,
    % Nome = criminoso,
    % Verbo = adora,
    % Artigo2 = um,
    % Nome2 = 'mac lanche feliz' ;
    % qualquer criminoso adora um mac lanche feliz

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = Nome2, Nome2 = criminoso,
    % Verbo = adora ;
    % qualquer criminoso adora qualquer criminoso

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = criminoso,
    % Verbo = adora,
    % Nome2 = 'mac lanche feliz' ;
    % qualquer criminoso adora qualquer mac lanche feliz

    % Artigo = qualquer,
    % Nome = 'mac lanche feliz',
    % Verbo = come,
    % Artigo2 = um,
    % Nome2 = criminoso ;
    % qualquer mac lanche feliz come um criminoso

    % Artigo = qualquer,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = come,
    % Artigo2 = um ;
    % qualquer mac lanche feliz come um mac lanche feliz

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = 'mac lanche feliz',
    % Verbo = come,
    % Nome2 = criminoso ;
    % qualquer mac lanche feliz come um criminoso

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = come ;
    % qualquer mac lanche feliz come qualquer mac lanche feliz

    % Artigo = qualquer,
    % Nome = 'mac lanche feliz',
    % Verbo = adora,
    % Artigo2 = um,
    % Nome2 = criminoso ;
    % qualquer mac lanche feliz adora um criminoso

    % Artigo = qualquer,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = adora,
    % Artigo2 = um ;
    % qualquer mac lanche feliz adora um mac lanche feliz

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = 'mac lanche feliz',
    % Verbo = adora,
    % Nome2 = criminoso ;
    % qualquer mac lanche feliz adora qualquer criminoso

    % Artigo = Artigo2, Artigo2 = qualquer,
    % Nome = Nome2, Nome2 = 'mac lanche feliz',
    % Verbo = adora.
    % qualquer mac lanche feliz adora qualquer mac lanche feliz