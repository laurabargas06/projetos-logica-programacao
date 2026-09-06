import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
enum StatusMatricula {
    TRANCADA,
    ATIVA,
    CONCLUIDA
}

interface Avaliavel {
    void adicionarNota(double nota) throws Exception;
    double calcularMedia();
}
abstract class Pessoa {
    private String nome;
    private int idade;
    private String CPF;

    public Pessoa(String nome, int idade, String cpf) {
        this.nome = nome;
        this.idade = idade;
        this.CPF = cpf;
    }

    public String getNome()  {
        return nome;
     }
    public String getCPF() {
         return CPF; 
        }
    public int getIdade() {
         return idade;
         }
    
    public void exibirDados(){
            System.out.println("Nome: "+ nome + ", CPF: " + CPF + ", Idade: " + idade);
    }
}
class Professor extends Pessoa {
    private String disciplina;
    private double salario;

    public Professor(String nome, int idade, String cpf, String disciplina, double salario) {
        super(nome, idade, cpf); 
        this.disciplina = disciplina;
        this.salario = salario;
    }

    public String getDisciplina() {
         return disciplina; 
        }
    public double getSalario() {
         return salario; 
        }

    @Override
    public void exibirDados() {
        System.out.println("Professor: " + getNome() + " | Disciplina: " + disciplina);
    }
}

class Aluno extends Pessoa implements Avaliavel {
    private String matricula;
    private List<Double> notas = new ArrayList<>();
    private StatusMatricula status;

    public Aluno(String nome, int idade, String cpf, String matricula, StatusMatricula status) {
        super(nome, idade, cpf);
        this.matricula = matricula;
        this.status = status;
    }

    @Override
    public void adicionarNota(double nota) throws Exception {
        if (this.status != StatusMatricula.ATIVA) {
            throw new Exception("Não é possível adicionar nota: o aluno não está com a matrícula ATIVA.");
        }
        if (nota < 0 || nota > 10) {
            throw new Exception("Nota inválida! A nota deve ser entre 0 e 10.");
        }
        this.notas.add(nota);
    }

    @Override
    public double calcularMedia() {
        if (notas.isEmpty()) return 0.0;
        
        double soma = 0;
        for (double n : notas) {
            soma += n;
        }
        return soma / notas.size();
    }

    public StatusMatricula getStatus() {
         return status;
         }

    @Override
    public void exibirDados() {
        System.out.println("Aluno: " + getNome() + " | Matrícula: " + matricula + " | Média: " + calcularMedia());
    }
}
class Turma {
    private String codigo;
    private Professor professor;
    private List<Aluno> alunos = new ArrayList<>();
    private int capacidadeMaxima;

    public Turma(String codigo, Professor professor, int capacidadeMaxima) {
        this.codigo = codigo;
        this.professor = professor;
        this.capacidadeMaxima = capacidadeMaxima;
    }

    public void adicionarAluno(Aluno aluno) throws Exception {
        if (alunos.size() >= capacidadeMaxima) {
            throw new Exception("Turma lotada! Limite de " + capacidadeMaxima + " alunos atingido.");
        }
        alunos.add(aluno);
    }

    public void gerarRelatorio() {
        System.out.println("=== TURMA: " + codigo + " ===");
        professor.exibirDados();
        System.out.println("---------------------------");
        System.out.println("Lista de Alunos:");
        
        for (Aluno aluno : alunos) {
            aluno.exibirDados();
            double media = aluno.calcularMedia();
            
            if (media >= 7.0) {
                System.out.println("Situação: APROVADO");
            } else if (media >= 5.0) {
                System.out.println("Situação: RECUPERAÇÃO");
            } else {
                System.out.println("Situação: REPROVADO");
            }
            System.out.println();
        }
    }
}
public class escola{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcao = -1;

        
        Professor prof = new Professor("Carlos", 40, "12345678901", "POO", 5000.0);
        Turma turma = new Turma("POO-2026", prof, 5);

        
        while (opcao != 0) {
            System.out.println("\n========== MENU ESCOLAR ==========");
            System.out.println("1 - Cadastrar novo Aluno na Turma");
            System.out.println("2 - Adicionar Nota a um Aluno");
            System.out.println("3 - Exibir Relatório da Turma");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");

            opcao = scanner.nextInt();
            scanner.nextLine(); // Limpa o buffer do teclado após ler número

            try {
                switch (opcao) {
                    case 1:
                        System.out.print("Nome do Aluno: ");
                        String nome = scanner.nextLine();
                        
                        System.out.print("Idade: ");
                        int idade = scanner.nextInt();
                        scanner.nextLine();
                        
                        System.out.print("CPF: ");
                        String cpf = scanner.nextLine();
                        
                        System.out.print("Matrícula: ");
                        String matricula = scanner.nextLine();

                        // Cria o aluno com status ATIVA por padrão
                        Aluno novoAluno = new Aluno(nome, idade, cpf, matricula, StatusMatricula.ATIVA);
                        turma.adicionarAluno(novoAluno);
                        
                        System.out.println(">> Aluno cadastrado com sucesso!");
                        break;

                    case 2:
                        System.out.println("Recurso para adicionar nota selecionado.");
                        // Aqui você pode implementar a busca do aluno para inserir a nota
                        break;

                    case 3:
                        turma.gerarRelatorio();
                        break;

                    case 0:
                        System.out.println("Encerrando o sistema...");
                        break;

                    default:
                        System.out.println("Opção inválida! Tente novamente.");
                }
            } catch (Exception e) {
                // Captura exceções da regra de negócio (ex: turma lotada, nota inválida)
                System.out.println(">> ERRO: " + e.getMessage());
            }
        }

        scanner.close();
    }
}

    
