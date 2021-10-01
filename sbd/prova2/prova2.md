# Prova 1

> Aluno: Heitor Freitas Ferreira  
> Matricula: 11921BCC026

## 1

### A

```sql
set search_path to sfp;

select cpf,nomepes,salariofun
from funcionario as f natural join pessoa
```

### B

```sql
set search_path to sfp;

select cpf,nomepes,salariofun, valorbol
from funcionario as f, pessoa as p, bolsista as b
where 
	f.idpes = p.idpes 
	and 
	b.idpes = p.idpes
	and
	f.salariofun<b.valorbol
```

### C

```sql
select cpf, nomepes, 'funcionario' as tipo, salariofun as valor from 
    funcionario as f natural join pessoa as p
union 
select cpf, nomepes, 'bolsista', valorbol as valor from 
    bolsista as b natural join pessoa as p
order by p.cpf;
```

### D

```sql
set search_path to sfp;

select p.cpf, p.nomepes
	from  pessoa as p
	where(
		select count(idati)
		from pesati as pa
		where pa.idpes = p.idpes
	) > 1
	
order by p.cpf
```

### E

```sql
set search_path to sfp;

select p.cpf,p.nomepes, pr.nomepro
	from  (pessoa as p natural join funcionario as f) left outer join projeto as pr on pr.idpes = f.idpes

order by p.nomepes
```

### F

```sql
set search_path to sfp;

select p.cpf, p.nomepes, count(p.idpes) as QtdeAtividades
	from  pessoa as p natural join bolsista as b natural join pesati as pa
	where(
		select count(idati)
		from pesati as pa
		where pa.idpes = p.idpes
	) > 3
	
group by p.cpf,p.nomepes
```

### G

```sql
set search_path to sfp;

select cpf, nomepes from (pessoa natural join projeto) p_pr
    where idpro = 1 and not exists (
        select idati from atividade where atividade.idpro = 1 and not exists (
            select idati from pesati where p_pr.idpes = pesati.idpes 
        )
    );
```

## 2

```sql
set search_path to sfp;

with recursive tAtivs(idati, idpro, nivel, idatisuper, descricaoati) as (
    select idati, idpro, 0 as nivel, idatisuper, descricaoati
    from atividade as base_case
    where base_case.idatisuper is NULL
        union all
    select filho.idati, filho.idpro, nivel + 1, filho.idatisuper, filho.descricaoati
    from tAtivs as pai, atividade as filho
    where pai.idati = filho.idatisuper
)

select idpro, nivel, idatisuper, idati, descricaoati from tAtivs ORDER BY idpro, nivel, idatisuper, descricaoati;
```

## 3

> Criação da view vtop

```sql
set search_path to sfp;

create or replace view vtop as 
	select func_rico.cpf, func_rico.nomepes, 'funcionario' as tipopes, func_rico.salariofun as maxvalue
	from 
		(funcionario natural join pessoa) func_rico
		where not exists(
			select salariofun from funcionario as func_pobre
			where func_rico.salariofun < func_pobre.salariofun
		)
		union 
		select bolsista_rico.cpf, bolsista_rico.nomepes, 'bolsista' as tipopes, bolsista_rico.valorbol as maxvalue
	from 
		(bolsista natural join pessoa) bolsista_rico
		where not exists(
			select valorbol from bolsista as bolsista_pobre
			where bolsista_rico.valorbol < bolsista_pobre.valorbol
		)
```

### A 

```sql
select idpes,nomepes, maxvalue from vtop where tipopes = 'funcionario'	
```

### B 

```sql
select idpes,nomepes, maxvalue from vtop where tipopes = 'bolsista'	
```

### C

```sql
select nomepes, maxvalue from vtop
    where tipopes = 'funcionario' and not (
        select idpes from bolsista where vtop.idpes = bolsista.idpes
    )
```
