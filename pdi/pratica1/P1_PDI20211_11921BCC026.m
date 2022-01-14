
function image_thresholded = quantizar(img)
  my_image = im2double(img);
  #[rows, columns, numberOfColorChannels] = size(my_image);
  image_thresholded = zeros(size(my_image));
 for ii=1:size(my_image,1)
    for jj=1:size(my_image,2)
        % get pixel value
        pixel=my_image(ii,jj);
          % check pixel value and assign new value
          if pixel<0.5
              image_thresholded(ii,jj)=0;
          else
              image_thresholded(ii,jj) = 1;
          end
      endfor
  endfor
  image_thresholded;
end
