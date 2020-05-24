struct ht{
    const static __int128 p=(1LL<<61)-1;
    __int128 x;
    ht operator +(ht ot){return (x+ot.x)%p;}
    ht operator -(ht ot){return (x-ot.x)%p;}
    ht operator *(ht ot){return (x*ot.x)%p;}
    bool operator !=(ht ot){return (x-ot.x)%p;}
    bool operator ==(ht ot){return !(*this!=(ot));}
    ht (){x=0;};
    ht(__int128 x){this->x=x;}
};
