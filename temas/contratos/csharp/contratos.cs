#define CONTRACTS_FULL

using System;
using System.Diagnostics.Contracts;

// Un IArray es una colección ordenada de objetos
[ContractClass(typeof(IArrayContract))]
public interface IArray{
    // La propiedad Item proporciona métodos para leer y editar entradas en rl array.
    Object this[int index]{
        get;
        set;
    }

    int aux {
        get;
    }

    //  Agrega un elemento a la lista. El valor devuelto es la posición en la que se insertó el nuevo elemento.
    int Add(Object valor);

    // Elimina todos los elementos de la lista
    void Clear();

    //Inserta valor en la matriz en el índice de posición.
    //El índice debe ser no negativo y menor o igual que el número de elementos en la matriz. Si el índice es igual al número
    // de elementos en la matriz, luego el valor se agrega al final.
    void Insert(int index, Object valor);

    // Elimina el item de la posicion del índice
    void RemoveAt(int index);
}

[ContractClassFor(typeof(IArray))]
internal abstract class IArrayContract : IArray{
    int IArray.Add(Object valor)    {
        // Devuelve el índice en el que se insertó un elemento.
        Contract.Ensures(Contract.Result<int>() >= -1);
        Contract.Ensures(Contract.Result<int>() < ((IArray)this).aux);
        return default(int);
    }
    Object IArray.this[int index]{
        //función arriba llamada
        get{
            Contract.Requires(index >= 0);
            Contract.Requires(index < ((IArray)this).aux);
            return default(int);
        }
        set{
            Contract.Requires(index >= 0);
            Contract.Requires(index < ((IArray)this).aux);
        }
    }
    public int aux {
        get {
            Contract.Requires(aux >= 0);
            Contract.Requires(aux <= ((IArray)this).aux);
            return default(int);
        }
    }

    void IArray.Clear() {
        Contract.Ensures(((IArray)this).aux == 0);
    }

    void IArray.Insert(int index, Object valor){
        Contract.Requires(index >= 0);
        //La añadimos directamente al final
        Contract.Requires(index <= ((IArray)this).aux);
        Contract.Ensures(((IArray)this).aux == Contract.OldValue(((IArray)this).aux) + 1);
    }

    void IArray.RemoveAt(int index){
        Contract.Requires(index >= 0);
        Contract.Requires(index < ((IArray)this).aux);
        Contract.Ensures(((IArray)this).aux == Contract.OldValue(((IArray)this).aux) - 1);
    }
}