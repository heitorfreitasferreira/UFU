package org.example.abstractfactory.factories;

import org.example.abstractfactory.products.Copo;
import org.example.abstractfactory.products.Garrafa;
import org.example.abstractfactory.products.Prato;
import org.example.abstractfactory.products.bidimentional.Copo2D;
import org.example.abstractfactory.products.bidimentional.Garrafa2D;
import org.example.abstractfactory.products.bidimentional.Prato2D;

public class Meseira2D implements Meseira {
    @Override
    public Prato fabricarPrato() {
        return new Prato2D();
    }
    @Override
    public Garrafa fabricarGarrafa() {
        return new Garrafa2D();
    }
    @Override
    public Copo fabricarCopo() {
        return new Copo2D();
    }

}
