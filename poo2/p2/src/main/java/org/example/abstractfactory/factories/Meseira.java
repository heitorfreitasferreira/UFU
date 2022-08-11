package org.example.abstractfactory.factories;

import org.example.abstractfactory.products.Copo;
import org.example.abstractfactory.products.Garrafa;
import org.example.abstractfactory.products.Prato;
public interface Meseira {
    public Prato fabricarPrato();
    public Garrafa fabricarGarrafa();
    public Copo fabricarCopo();
}
