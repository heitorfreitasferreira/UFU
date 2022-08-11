package org.example.abstractfactory.factories;

import org.example.abstractfactory.products.Copo;
import org.example.abstractfactory.products.Garrafa;
import org.example.abstractfactory.products.Prato;
import org.example.abstractfactory.products.tridimentional.Copo3D;
import org.example.abstractfactory.products.tridimentional.Garrafa3D;
import org.example.abstractfactory.products.tridimentional.Prato3D;

public class Meseira3D implements Meseira {
    @Override
    public Prato fabricarPrato() {
        return new Prato3D();
    }
    @Override
    public Garrafa fabricarGarrafa() {
        return new Garrafa3D();
    }
    @Override
    public Copo fabricarCopo() {
        return new Copo3D();
    }

}
