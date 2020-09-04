member(X, [X|_]).
member(X, [_|T]) :- member(X, T).
% [trace]  ?- member(heitor,[valter,betoh,seiji]).
%    Call: (10) member(heitor, [valter, betoh, seiji]) ? creep
%    Call: (11) member(heitor, [betoh, seiji]) ? creep
%    Call: (12) member(heitor, [seiji]) ? creep
%    Call: (13) member(heitor, []) ? creep
%    Fail: (13) member(heitor, []) ? creep
%    Fail: (12) member(heitor, [seiji]) ? creep
%    Fail: (11) member(heitor, [betoh, seiji]) ? creep
%    Fail: (10) member(heitor, [valter, betoh, seiji]) ? creep
% false.

% [trace]  ?- member(heitor,[seiji,betoh,seiji,heitor]).
%    Call: (10) member(heitor, [seiji, betoh, seiji, heitor]) ? creep
%    Call: (11) member(heitor, [betoh, seiji, heitor]) ? creep
%    Call: (12) member(heitor, [seiji, heitor]) ? creep
%    Call: (13) member(heitor, [heitor]) ? creep
%    Exit: (13) member(heitor, [heitor]) ? creep
%    Exit: (12) member(heitor, [seiji, heitor]) ? creep
%    Exit: (11) member(heitor, [betoh, seiji, heitor]) ? creep
%    Exit: (10) member(heitor, [seiji, betoh, seiji, heitor]) ? creep
% true .