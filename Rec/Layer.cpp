#include "Layer.h"
#include <vector>
#include <iostream>
#include <cmath>

namespace ReconLib{

    int mulMatriz(Matriz m, Matriz f){
        int res = 0;
        for(int i=0;i<m.ancho;i++){
            for(int j=0;j<m.alto;j++){
                res+=m.get(i,j)*f.get(i,j);
                //std::cout<<"i: "<<i<<" j: "<<j<<" res: "<<res<<'\n';
            }
        }
        return res;
    }

    Matriz subMatriz(Matriz m,int i, int j, int kernel){
        Matriz sub(kernel);
        for(int x=0;x<kernel;x++){
            for(int y=0;y<kernel;y++){
                sub.set(x,y,m.get(i+x,j+y));
            }
        }
        return sub;
    }

    void Layer::setFilters(){
        Matriz fil1(3,3); //bottom border
        Matriz fil2(3,3); //right border
        Matriz fil3(3,3); //top border
        Matriz fil4(3,3); //lefth border


        std::cout<<"Setting Filter1";
        fil1.set(0,0,-1);
        fil1.set(0,1,-1);
        fil1.set(0,2,-1);
        fil1.set(1,0,1);
        fil1.set(1,1,1);
        fil1.set(1,2,1);
        fil1.set(2,0,0);
        fil1.set(2,1,0);
        fil1.set(2,2,0);

        std::cout<<"Setting Filter2";
        fil2.set(0,0,-1);
        fil2.set(0,1,1);
        fil2.set(0,2,0);
        fil2.set(1,0,-1);
        fil2.set(1,1,1);
        fil2.set(1,2,0);
        fil2.set(2,0,-1);
        fil2.set(2,1,1);
        fil2.set(2,2,0);

        std::cout<<"Setting Filter3";
        fil3.set(0,0,0);
        fil3.set(0,1,0);
        fil3.set(0,2,0);
        fil3.set(1,0,1);
        fil3.set(1,1,1);
        fil3.set(1,2,1);
        fil3.set(2,0,-1);
        fil3.set(2,1,-1);
        fil3.set(2,2,-1);

        std::cout<<"Setting Filter4";
        fil4.set(0,0,0);
        fil4.set(0,1,1);
        fil4.set(0,2,-1);
        fil4.set(1,0,0);
        fil4.set(1,1,1);
        fil4.set(1,2,-1);
        fil4.set(2,0,0);
        fil4.set(2,1,1);
        fil4.set(2,2,-1);

        this->filters.push_back(fil1);
        this->filters.push_back(fil2);
        this->filters.push_back(fil3);
        this->filters.push_back(fil4);
        // this->filters.at(0).mostrar();
        // this->filters.at(1).mostrar();
        // this->filters.at(2).mostrar();
        // this->filters.at(3).mostrar();
    }

    std::vector<Matriz> Layer::convolution(int fill_num, Matriz m){
        std::vector<Matriz> convLayer;
        int contador = 0;
        std::cout<<"convolutional Layer \n";
        for(Matriz fil:this->filters){
            if(contador<fill_num){
                fil.mostrar();
                Matriz mf(m.ancho-(fil.ancho-1),m.alto-(fil.alto-1));
                std::cout<<"ancho mf: "<< mf.ancho << "alto mf: "<< mf.alto<<'\n';
                //int o = mulMatriz(m,fil);
                for(int i=0;i<mf.alto;i++){
                    for(int j=0;j<mf.ancho;j++){
                        Matriz mi=subMatriz(m,i,j,fil.ancho);
                        //mi.mostrar();
                        //subMatriz(m,i,j,fil.ancho).mostrar();
                        mf.set(i,j,mulMatriz(mi,fil));
                    }
                }
                std::cout<<"El resultado del filtro es: "<<'\n';
                mf.mostrar();
                std::cout<<'\n';
                convLayer.push_back(mf);
            }
            else{
                break;
            }
            contador++;
        }
        return convLayer;
    }

    int grtNumMatriz(Matriz m){
        int great=m.get(0,0);
        for(int i=0;i<m.alto;i++){
            for(int j=0;j<m.ancho;j++){
                if(m.get(i,j)>great){
                    great = m.get(i,j);
                    //std::cout<< great <<'\n';
                }
            }
        }
        //std::cout<< m.ancho <<" "<<m.alto<<" " <<great <<'\n';
        return great;
    }

    Matriz paddingAncho(Matriz m){
        if(m.ancho%2!=0){
            Matriz mAncho(m.ancho+1,m.alto);
            for(int i=0;i<m.alto;i++){
                for(int j=0;j<m.ancho;j++){
                    mAncho.set(i,j,m.get(i,j));
                }
            }
            for(int n=0;n<m.alto;n++){
                mAncho.set(n,m.ancho,0);
            }
            return mAncho;
        }
    }

    Matriz paddingAlto(Matriz m){
            Matriz mAlto(m.ancho,m.alto+1);
            for(int i=0;i<m.alto;i++){
                for(int j=0;j<m.ancho;j++){
                    mAlto.set(i,j,m.get(i,j));
                }
            }
            for(int n=0;n<m.ancho;n++){
                mAlto.set(m.alto,n,0);
            }
            return mAlto;
    }

    Matriz padding(Matriz m){
        if(m.ancho%2!=0){
            return paddingAncho(m);
        }
        else if(m.alto%2!=0)
        {
            return paddingAlto(m);
        }
        else if(m.alto%2!=0 && m.ancho%2!=0){
            Matriz m2(m.ancho+1,m.alto);
            m2 = paddingAncho(m);
            Matriz m3(m2.ancho,m2.alto+1);
            m3 = paddingAlto(m2); 
        }
        return m;
        
    }

    std::vector<int> paddSize(Matriz m){
        std::vector<int> size;
        if(m.ancho%2!=0){
            size.push_back(m.ancho+1);
            size.push_back(m.alto);
            return size;
        }
        else if(m.alto%2!=0)
        {
            size.push_back(m.ancho);
            size.push_back(m.alto+1);
            return size;
        }
        else if(m.alto%2!=0 && m.ancho%2!=0){
            size.push_back(m.ancho+1);
            size.push_back(m.alto+1);
            return size; 
        }
        size.push_back(m.ancho);
        size.push_back(m.alto);
        return size;
    }

    Matriz Layer::maxpooling(Matriz matrixEntrada)
    {
        int kernel = 2;
        std::vector<int> size = paddSize(matrixEntrada);
        Matriz matrix(size.at(0),size.at(1));
        matrix = padding(matrixEntrada);
        Matriz poolingM(matrix.ancho / kernel, matrix.alto / kernel);
        Matriz subm(kernel, kernel);
        for (int i = 0; i < poolingM.alto; i++)
        {
            for (int j = 0; j < poolingM.ancho; j++)
            {
                subm = subMatriz(matrix, i * kernel, j * kernel, kernel);
                //subm.mostrar();
                poolingM.set(i, j, grtNumMatriz(subm));
            }
        }
        return poolingM;
    }


    std::vector<std::vector<int>> Layer::flatten(std::vector<Matriz> vector_matrix){
        std::vector<std::vector<int>> flattenVector;
        for(Matriz m:vector_matrix){
            std::vector<int> vn;
            int numeros = (m.alto*m.ancho);
            for(int i = 0;i<numeros;i++){
                vn.push_back(m.numeros[i]);
                //std::cout<< m.numeros[i] <<'\n';
            }
            flattenVector.push_back(vn);
        }
        return flattenVector;
    }

	int Layer::ReLu(int relu){
        if (relu>0){
            return relu;
        }
        return 0;
    }
	// Matriz optimize(int label_num,Matriz matrix,int ages);
}