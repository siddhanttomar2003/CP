import java.io.*;
import java.util.*;

public class Main {

    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // Read N
        int m = Integer.parseInt(st.nextToken()); // Read M

        // Maps for column and row data
        Map<Integer, List<Pair>> mp_c = new HashMap<>();
        Map<Integer, List<Pair>> mp_r = new HashMap<>();
        boolean check = true;

        // Read the input data
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            char c = st.nextToken().charAt(0);

            mp_c.putIfAbsent(col, new ArrayList<>());
            mp_c.get(col).add(new Pair(row, c));

            mp_r.putIfAbsent(row, new ArrayList<>());
            mp_r.get(row).add(new Pair(col, c));
        }

        // Check columns
        for (int col : mp_c.keySet()) {
            List<Pair> temp = mp_c.get(col);
            temp.sort(Comparator.comparingInt(p -> p.position));

            int posLastWhite = -1;
            int posFirstBlack = -1;

            for (Pair p : temp) {
                int pos = p.position;
                char c = p.color;

                if (c == 'W') {
                    posLastWhite = pos;
                } else if (posFirstBlack == -1) {
                    posFirstBlack = pos;
                }
            }

            if (posLastWhite != -1 && posFirstBlack != -1 && posLastWhite < posFirstBlack) {
                check = false;
                break;
            }
        }

        // Check rows
        for (int row : mp_r.keySet()) {
            List<Pair> temp = mp_r.get(row);
            temp.sort(Comparator.comparingInt(p -> p.position));

            int posLastWhite = -1;
            int posFirstBlack = -1;

            for (Pair p : temp) {
                int pos = p.position;
                char c = p.color;

                if (c == 'W') {
                    posLastWhite = pos;
                } else if (posFirstBlack == -1) {
                    posFirstBlack = pos;
                }
            }

            if (posLastWhite != -1 && posFirstBlack != -1 && posLastWhite < posFirstBlack) {
                check = false;
                break;
            }
        }

        // Print the result
        if (check) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static void main(String[] args) throws IOException {
        solve();
    }

    static class Pair {
        int position;
        char color;

        Pair(int position, char color) {
            this.position = position;
            this.color = color;
        }
    }
}
