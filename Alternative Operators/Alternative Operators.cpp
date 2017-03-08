/**
 *  Ohhhh this is fun!
 */

%:include <iostream>

int main(int argc, char *argv<::>)
<%
    if (true and (true not_eq false)) <%
        std::cout << "Hello, World" << '\n';
    %>
%>
