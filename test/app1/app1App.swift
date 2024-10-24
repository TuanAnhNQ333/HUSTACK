//
//  app1App.swift
//  app1
//
//  Created by Macbook on 8/10/24.
//

import SwiftUI

@main
struct app1App: App {
    var body: some Scene {
        DocumentGroup(newDocument: app1Document()) { file in
            ContentView(document: file.$document)
        }
    }
}
