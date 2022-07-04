public abstract class FormaDecorator extends Forma {
    protected Forma formaDecorada;
    public FormaDecorator(Forma formaDecorada) {
        this.formaDecorada = formaDecorada;
    }
    public String getDescricao() {
        return formaDecorada.getDescricao() + " | " + super.getDescricao();
    }
    
}
