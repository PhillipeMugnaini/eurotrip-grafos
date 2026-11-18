# Eurotrip · Dados e fontes

Pesquisa realizada em 16/11/2026. A base contém sete cidades, seis países europeus e 18 ligações. A tabela registra os valores consultados para que seja possível conferir os pesos do projeto caso as páginas de oferta mudem.

## Como usar

Extraia o ZIP e copie as pastas `data/` e `docs/` para a raiz do projeto. Preserve o separador `;` e o ponto decimal dos CSVs. O identificador `ROM` representa a cidade de Roma no grafo. Os voos pesquisados usam o aeroporto Fiumicino (`FCO`).

## Cidades e pontos turísticos

| ID | Cidade e país | Ponto turístico | Fonte |
|---|---|---|---|
| CWB | Curitiba, Brasil | Jardim Botânico | [Turismo Curitiba](https://turismo.curitiba.pr.gov.br/conteudo/jardim-botanico/1674) |
| ZRH | Zurique, Suíça | Centro histórico e Lago de Zurique | [Centro histórico](https://www.zuerich.com/en/sightseeing-activities/places-to-visit/zurichs-old-town) e [Lago de Zurique](https://www.zuerich.com/en/visit/nature/waterside-city-walk) |
| OSL | Oslo, Noruega | Ópera de Oslo | [Oslo Opera House](https://www.operaen.no/en/your-visit-at-oslo-operahouse/practical-information/) |
| ROM | Roma, Itália | Coliseu | [Parco archeologico del Colosseo](https://colosseo.it/en/opening-times-and-tickets/) |
| ATH | Atenas, Grécia | Acrópole | [Hellenic Heritage](https://www.hh.gr/en/destinations/acropolis-of-athens/) |
| DUB | Dublin, Irlanda | Trinity College | [Trinity College Dublin](https://www.tcd.ie/study/international/visit/individuals/) |
| PRG | Praga, República Tcheca | Ponte Carlos | [Prague City Tourism](https://prague.eu/en/objevujte/charles-bridge-karluv-most/) |

## Rotas e pesos

As 16 rotas aéreas usam ofertas de ida publicadas por companhias ou buscadores. Cada oferta registra o preço e a duração da mesma opção, incluindo o tempo de conexão indicado pela fonte. As duas rotas ferroviárias usam tarifas mínimas publicadas pelas operadoras. A duração Zurique–Roma é a referência aproximada da SBB.

| Aresta | Itinerário e operador | Data da viagem | Preço publicado | Custo no CSV (R$) | Duração | Distância (km) | Fonte do preço e horário |
|---|---|---|---:|---:|---|---:|---|
| CWB–DUB | CWB → GRU → LHR → DUB · LATAM Airlines | 23/11/2026 | BRL 2.256,00 | 2.256,00 | 18 h 25 min | 10269 | [Oferta](https://www.kayak.com.br/voos/Curitiba-Afonso-Pena-CWB/Dublin-DUB) |
| CWB–ZRH | CWB → VCP → LIS → BCN → ZRH · Várias companhias (KAYAK) | 25/01/2027 | BRL 3.424,00 | 3.424,00 | 22 h 55 min | 10126 | [Oferta](https://www.kayak.com.br/voos/Curitiba-Afonso-Pena-CWB/Zurich-ZRH) |
| CWB–ROM | CWB → GRU → MAD → FCO · Air Europa (KAYAK) | 15/12/2026 | BRL 3.123,00 | 3.123,00 | 27 h 05 min | 10069 | [Oferta](https://www.kayak.com.br/voos/Curitiba-Afonso-Pena-CWB/Roma-Fiumicino-FCO?cc=br&lc=pt) |
| DUB–OSL | DUB → OSL · Scandinavian Airlines | 18/01/2027 | USD 57,00 | 322,83 | 2 h 10 min | 1291 | [Oferta](https://www.kayak.com/flight-routes/Dublin-DUB/Oslo-Gardermoen-OSL) |
| DUB–PRG | DUB → PRG · Ryanair | 06/01/2027 | EUR 30,17 | 188,85 | 2 h 25 min | 1454 | [Oferta](https://www.ryanair.com/gb/en/flights/flights-from-dublin-to-prague) |
| DUB–ZRH | DUB → ZRH · Aer Lingus | 17/11/2026 | USD 60,00 | 339,82 | 2 h 30 min | 1238 | [Oferta](https://www.kayak.com/flight-routes/Dublin-DUB/Zurich-ZRH) |
| DUB–ROM | DUB → FCO · Ryanair | 24/11/2026 | EUR 37,04 | 231,85 | 3 h 00 min | 1886 | [Oferta](https://www.ryanair.com/gb/en/flights/flights-from-dublin-to-rome) |
| DUB–ATH | DUB → ATH · Ryanair | 19/11/2026 | USD 87,00 | 492,74 | 4 h 05 min | 2876 | [Oferta](https://www.kayak.com/flight-routes/Dublin-DUB/Athens-Eleftherios-V--ATH) |
| OSL–PRG | OSL → PRG · Norwegian | 05/01/2027 | EUR 42,00 | 262,90 | 2 h 00 min | 1140 | [Oferta](https://piratefly.com/flights/oslo-to-prague) |
| OSL–ZRH | OSL → ZRH · Norwegian | 18/12/2026 | NOK 875,00 | 518,20 | 2 h 20 min | 1426 | [Oferta](https://www.kayak.no/fly/Oslo-og-andre-flyplasser-OSL/Zurich-ZRH) |
| OSL–ROM | OSL → FCO · Wizz Air | 31/12/2026 | NOK 417,00 | 246,96 | 3 h 20 min | 2046 | [Oferta](https://www.kayak.no/fly/Oslo-og-andre-flyplasser-OSL/Roma-Fiumicino-FCO) |
| OSL–ATH | OSL → ATH · Aegean Airlines | 31/01/2027 | USD 97,00 | 549,38 | 3 h 45 min | 2635 | [Oferta](https://www.kayak.com/flight-routes/Oslo-Gardermoen-OSL/Athens-Eleftherios-V--ATH) |
| PRG–ZRH | Praha hl.n. → Zürich HB (EN 40458 Canopus) · České dráhy | Sem data específica | a partir de CZK 2.430,00 | 622,77 | 15 h 40 min | 915 | [Operadora](https://www.cd.cz/en/typy-jizdenek/vlakem-do-evropy/-27833/) · [Horário e quilometragem do Canopus](https://back-on-track.eu/night-train/cd-praha-zurich/) |
| PRG–ROM | PRG → FCO · Wizz Air | 25/11/2026 | USD 33,00 | 186,90 | 1 h 55 min | 935 | [Oferta](https://www.kayak.com/flight-routes/Vaclav-Havel-Prague-PRG/Rome-Fiumicino-FCO) |
| PRG–ATH | PRG → ATH · Sky Express | 18/02/2027 | USD 96,00 | 543,71 | 2 h 30 min | 1556 | [Oferta](https://www.kayak.com/flight-routes/Vaclav-Havel-Prague-PRG/Athens-Eleftherios-V--ATH) |
| ZRH–ROM | Zürich HB → Milano Centrale → Roma Termini · EuroCity + Frecciarossa | Sem data específica | a partir de CHF 80,00 | 540,43 | cerca de 7 h 00 min | 828 | [Operadora](https://www.sbb.ch/en/leisure-holidays/europe/countries-cities/italy/zurich-rome.html) · [Zürich–Milano, 254 km](https://www.eurotreni.com/OrariTreni/Orari/2026/ItaliaSvizzera/viaChiasso/Ec10-29.html) e [Milano–Roma, 574 km](https://italianrailpass.com/routes/milan-rome) |
| ZRH–ATH | ZRH → ATH · SWISS | 15/12/2026 | USD 102,00 | 577,70 | 2 h 35 min | 1639 | [Oferta](https://www.kayak.com/flight-routes/Zurich-ZRH/Athens-Eleftherios-V--ATH) |
| ROM–ATH | FCO → ATH · Ryanair | 01/02/2027 | BRL 212,00 | 212,00 | 2 h 00 min | 1085 | [Oferta](https://www.kayak.com.br/voos/Roma-Fiumicino-FCO/Atenas-Eleftherios-V--ATH) |

## Critérios de cálculo

- Preço. O custo em reais usa ofertas em BRL como publicadas. Para as demais moedas, apliquei o câmbio de referência de 13/11/2026 do Banco Central Europeu, em unidades de moeda por euro. EUR 1 = BRL 6,2595, USD 1,1052, NOK 10,5695, CZK 24,424 e CHF 0,9266. Para converter um valor, multiplique por 6,2595 e divida pela taxa da moeda original. O CSV arredonda o resultado aos centavos. [Tabela de câmbio](https://www.ecb.europa.eu/stats/exchange/eurofxref/shared/pdf/2026/11/20261113.pdf)
- Tempo. Converti os minutos publicados em horas decimais. Por exemplo, 18 h 25 min = 18,4167 h. O trem Canopus tem horário de referência de 17h25 às 09h05 do dia seguinte. A SBB informa cerca de 7 h para Zurique–Roma via Milão.
- Distância aérea. Somei as distâncias de grande círculo de cada par consecutivo de aeroportos usando a fórmula de Haversine e raio terrestre médio de 6.371,0088 km. O CSV arredonda a soma ao quilômetro. O valor é uma medida geográfica baseada em coordenadas publicadas. A trajetória efetivamente voada pode variar. [Bases do OurAirports](https://ourairports.com/data/) · [CSV de aeroportos](https://davidmegginson.github.io/ourairports-data/airports.csv)
- Distância ferroviária. Praga–Zurique usa os 915 km publicados para o Canopus. Zurique–Roma soma 254 km de Zürich HB a Milano Centrale e 574 km de Milano Centrale a Roma Termini, conforme as referências da tabela.
- Datas e sentidos. As ofertas foram publicadas para datas diferentes e podem expirar. O grafo existente usa o mesmo peso para ambos os sentidos de cada ligação. A pesquisa documenta o sentido exibido na tabela. A soma das arestas é uma comparação para o trabalho acadêmico. Para montar uma viagem reservável, seria necessário alinhar os horários, as datas e os deslocamentos entre estações e aeroportos.

## Coordenadas usadas nas distâncias aéreas

| IATA | Aeroporto no OurAirports | Latitude | Longitude |
|---|---|---:|---:|
| ATH | Athens Eleftherios Venizelos International Airport | 37.93640100 | 23.94450000 |
| BCN | Josep Tarradellas Barcelona-El Prat Airport | 41.29710000 | 2.07846000 |
| CWB | Curitiba-Afonso Pena International Airport | -25.52850000 | -49.17580000 |
| DUB | Dublin Airport | 53.42871300 | -6.26212100 |
| FCO | Rome–Fiumicino Leonardo da Vinci International Airport | 41.80453200 | 12.25199800 |
| GRU | São Paulo/Guarulhos–Governor André Franco Montoro International Airport | -23.43127400 | -46.46995400 |
| LHR | London Heathrow Airport | 51.47074800 | -0.45990900 |
| LIS | Lisbon Humberto Delgado Airport | 38.78130000 | -9.13592000 |
| MAD | Adolfo Suárez Madrid–Barajas Airport | 40.49340700 | -3.57224900 |
| OSL | Oslo-Gardermoen International Airport | 60.19390100 | 11.10040000 |
| PRG | Václav Havel Airport Prague | 50.10087400 | 14.25991100 |
| VCP | Viracopos International Airport | -23.00740400 | -47.13450200 |
| ZRH | Zürich Airport | 47.45805600 | 8.54805600 |

## Verificação da base

A estrutura do grafo continua conexa. Graus verificados por cidade: CWB = 3, ZRH = 6, OSL = 5, ROM = 6, ATH = 5, DUB = 6, PRG = 5. Todas as linhas possuem custo, distância e tempo positivos. Os valores do CSV foram atualizados e podem ser usados pela leitura dos dados da aplicação assim que ela estiver integrada. Os exemplos escritos diretamente no código e nos testes da Etapa 0 são dados de teste.
