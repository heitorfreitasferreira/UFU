% Pr�tica 02 - HEITOR FREITAS FERREIRA

art8 = imread('art8.png');
art8 = double(art8);
art8(:,:,2) = zeros(256,256);
label = 0;
for ii=1:size(art8,1)
  for jj=1:size(art8,2)
    pixel=art8(ii,jj,1);


    cima=art8(ii-1,jj,1);
    esquerda=art8(ii,jj-1,1);
    
    if pixel==1
      if cima==0 && esquerda==0
        label++;
        art8(ii,jj,2)=label;
      elseif cima==1 && esquerda==0
        art8(ii,jj,2)=art8(ii-1,jj,2);
      elseif cima==0 && esquerda==1
        art8(ii,jj,2)=art8(ii,jj-1,2);
      elseif cima==1 && esquerda==1
        art8(ii,jj,2)=min(art8(ii-1,jj,2),art8(ii,jj-1,2));
      end
    end
  endfor
endfor
for ii=1:size(art8,1)
  for jj=1:size(art8,2)
    
    art8(ii,jj,1)=art8(ii,jj,2)/8;
  endfor
endfor

figure, imshow(art8,'InitialMagnification','fit');
