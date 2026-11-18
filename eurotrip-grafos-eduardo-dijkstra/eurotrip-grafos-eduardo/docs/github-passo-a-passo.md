# GitHub - passo a passo do trio

## 1. Phillipe ou qualquer integrante cria o repositorio remoto

No GitHub, criar um repositorio chamado `eurotrip-grafos`, de preferencia
**vazio** (sem README e sem .gitignore para evitar conflitos com o ZIP).
Convidar Lucas e Eduardo em `Settings > Collaborators`.

## 2. Subir a estrutura inicial uma unica vez

Extrair o ZIP `eurotrip-grafos-etapa0.zip` e abrir a pasta no VS Code.
No terminal, dentro de `eurotrip-grafos-etapa0`:

```bash
git init -b main
git add .
git commit -m "chore: cria estrutura inicial e contratos"
git remote add origin https://github.com/SEU_USUARIO/eurotrip-grafos.git
git push -u origin main
```

Se Git pedir identidade, executar com os dados de sua conta:

```bash
git config --global user.name "Seu Nome"
git config --global user.email "seu-email@example.com"
```

Se sua instalacao for muito antiga e `git init -b main` nao funcionar,
execute `git init` seguido de `git branch -M main`.

## 3. Cada integrante clona o repositorio

```bash
git clone https://github.com/SEU_USUARIO/eurotrip-grafos.git
cd eurotrip-grafos
```

Criar uma branch (cada integrante usa APENAS a sua):

Lucas:
```bash
git switch -c feature/grafo
```

Eduardo:
```bash
git switch -c feature/dijkstra
```

Phillipe:
```bash
git switch -c feature/prim
```

## 4. Salvar e publicar o trabalho de cada um

```bash
git status
git add .
git commit -m "feat: implementa minha parte"
git push -u origin NOME_DA_SUA_BRANCH
```

Apos o primeiro `push -u`, os proximos podem ser apenas `git push`.

Abrir um Pull Request da branch para `main`, solicitar revisao e fazer merge.
Antes de iniciar uma nova tarefa, atualizar a branch a partir da main.
Nao editar os `.hpp` compartilhados sem combinar com o grupo.

## 5. Compilar (Linux / macOS / Windows com compilador e CMake instalados)

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Linux/macOS: `./build/eurotrip`. No Windows, o executavel pode estar em
`build\eurotrip.exe` (MinGW) ou `build\Debug\eurotrip.exe` (MSVC).

**Nao subir a pasta `build/`**. Ela ja esta no `.gitignore`.
