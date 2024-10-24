//
//  ContentView.swift
//  app1
//
//  Created by Macbook on 8/10/24.
//

import SwiftUI

struct ContentView: View {
    @Binding var document: app1Document

    var body: some View {
        TextEditor(text: $document.text)
    }
}

#Preview {
    ContentView(document: .constant(app1Document()))
}
