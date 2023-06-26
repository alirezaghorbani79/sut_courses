function ZC = ZeroX(x,y)
    zci = @(v) find(v(:).*circshift(v(:), [-1 0]) <= 0);                    % Returns Approximate Zero-Crossing Indices Of Argument Vector
    zxidx = zci(y);
    for k1 = 1:numel(zxidx)
        idxrng = max([1 zxidx(k1)-1]):min([zxidx(k1)+1 numel(y)]);
        xrng = x(idxrng);
        yrng = y(idxrng);
        ZC(k1) = interp1( yrng(:), xrng(:), 0, 'linear', 'extrap' );
    end
end
    